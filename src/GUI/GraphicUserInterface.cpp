//
// Created by donato on 22/11/19.
//

#include "GraphicUserInterface.h"
#include <gtk/gtk.h>

static GtkEntryBuffer *buffer_x = NULL, *buffer_y = NULL, *buffer_mines = NULL;

static GtkWidget *window, *grid, *missing_counter;

static GtkApplication *app;

struct pass_struct {
    GraphicUserInterface *gui;
    Box *box;
};

GraphicUserInterface::GraphicUserInterface() : GraphicUserInterface(new Player()) {}

GraphicUserInterface::GraphicUserInterface(Player *player) : GameInterface(){
    g_print("GUI CREATED\n");
    this->player = player;
}

GraphicUserInterface::~GraphicUserInterface() {
    delete this->field;
    g_print("GUI DELETED\n");
}

void GraphicUserInterface::setup_new_game() {

}

Coordinates* GraphicUserInterface::input_coordinates() {
    return new Coordinates();
}

void GraphicUserInterface::update_screen() {
    GtkWidget *button;
    Box *box;
    char buff[50];

    sprintf(buff, "Missing mines: %d", field->get_missing());
    gtk_label_set_text(GTK_LABEL(missing_counter), buff);
    for(int j = 0; j < this->field->get_len_y(); j++){
        for(int i = 0; i < this->field->get_len_x(); i++){
            box = field->get_box_at(i, j);
            button = gtk_grid_get_child_at(GTK_GRID(grid), i, j);
            gtk_button_set_label(GTK_BUTTON(button), " ");
            if(box->is_marked()){
                gtk_button_set_label(GTK_BUTTON(button), box->get_string_display().c_str());
            }
            else if(box->is_triggered()){
                gtk_button_set_label(GTK_BUTTON(button), box->get_string_display().c_str());
                gtk_widget_set_sensitive(button, FALSE);
            }
        }
    }
}

void GraphicUserInterface::reveal_screen() {
    GtkWidget *button;
    Box *box;
    for(int j = 0; j < this->field->get_len_y(); j++){
        for(int i = 0; i < this->field->get_len_x(); i++){
            box = field->get_box_at(i, j);
            button = gtk_grid_get_child_at(GTK_GRID(grid), i, j);
            if(box->get_type() == Box::MINE_TYPE)
                gtk_button_set_label(GTK_BUTTON(button), "X");
        }
    }
}

void GraphicUserInterface::win_display() {
    GtkWidget *dialog;

    dialog = gtk_message_dialog_new(
            GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_OTHER,
            GTK_BUTTONS_CLOSE,
            "Hai vinto!");

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    gtk_widget_destroy(window);
    delete this->field;
}

void GraphicUserInterface::lose_display() {
    GtkWidget *dialog;

    dialog = gtk_message_dialog_new(
            GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_OTHER,
            GTK_BUTTONS_CLOSE,
            "Hai perso!");

    GraphicUserInterface::reveal_screen();
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    gtk_widget_destroy(window);
    delete this->field;
}

int GraphicUserInterface::init_window(int argc, char **argv) {
    int status;

    app = gtk_application_new("mines.donato.com", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), this); //TESTA DI CAZZO
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

void GraphicUserInterface::activate(GtkApplication *app, gpointer data) {
    GraphicUserInterface *gui = reinterpret_cast<GraphicUserInterface*>(data);

    GtkWidget *window;
    GtkWidget *button_box;
    GtkWidget *start_button;
    GtkWidget *box;
    GtkWidget *label_x, *label_y, *label_mines;
    GtkWidget *entry_x, *entry_y, *entry_mines;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Mines");

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_container_set_border_width(GTK_CONTAINER(box), 100);

    label_x = gtk_label_new("field \"x\" attribute");
    gtk_container_add(GTK_CONTAINER(box), label_x);
    buffer_x = gtk_entry_buffer_new("", 0);
    entry_x = gtk_entry_new();
    gtk_entry_set_buffer(GTK_ENTRY(entry_x), buffer_x);
    gtk_container_add(GTK_CONTAINER(box), entry_x);
    label_y = gtk_label_new("field \"y\" attribute");
    gtk_container_add(GTK_CONTAINER(box), label_y);
    buffer_y = gtk_entry_buffer_new("", 0);
    entry_y = gtk_entry_new();
    gtk_entry_set_buffer(GTK_ENTRY(entry_y), buffer_y);
    gtk_container_add(GTK_CONTAINER(box), entry_y);
    label_mines = gtk_label_new("mines: ");
    gtk_container_add(GTK_CONTAINER(box), label_mines);
    buffer_mines = gtk_entry_buffer_new("", 0);
    entry_mines = gtk_entry_new();
    gtk_entry_set_buffer(GTK_ENTRY(entry_mines), buffer_mines);
    gtk_container_add(GTK_CONTAINER(box), entry_mines);

    //setting defaults
    gtk_entry_buffer_set_text(GTK_ENTRY_BUFFER(buffer_x), std::to_string(Field::STD_X).c_str(), 2);
    gtk_entry_buffer_set_text(GTK_ENTRY_BUFFER(buffer_y), std::to_string(Field::STD_Y).c_str(), 2);
    gtk_entry_buffer_set_text(GTK_ENTRY_BUFFER(buffer_mines), std::to_string(Field::STD_MINES).c_str(), 2);

    button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add(GTK_CONTAINER(box), button_box);

    start_button = gtk_button_new_with_label("Start");
    g_signal_connect(start_button, "clicked", G_CALLBACK(GraphicUserInterface::start_game), gui);
    gtk_container_add(GTK_CONTAINER(button_box), start_button);
    gtk_widget_show_all(window);
}

void GraphicUserInterface::start_game(GtkApplication *app, gpointer data) {
    GraphicUserInterface *gui = reinterpret_cast<GraphicUserInterface*>(data);

    GtkWidget *box;
    GtkWidget *button;

    //setting up the game
    gui->field = new Field(
            atoi(gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(buffer_x))),
            atoi(gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(buffer_y))),
            atoi(gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(buffer_mines)))
            );

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Actual Game");
    gtk_container_set_border_width(GTK_CONTAINER(window), 30);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_box_set_spacing(GTK_BOX(box), 10);

    missing_counter = gtk_label_new("Missing mines: ");
    gtk_container_add(GTK_CONTAINER(box), missing_counter);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(box), grid);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 2);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 2);

    std::vector<std::vector<pass_struct*>> s;
    //creating the matrix
    s.resize(gui->field->get_len_x());
    for(int j = 0; j < gui->field->get_len_x(); j++){
        s[j].resize(gui->field->get_len_y());
    }

    for(int j = 0; j < gui->field->get_len_y(); j++){
        for(int i = 0; i < gui->field->get_len_x(); i++){
            s[i][j] = new pass_struct;
        }
    }

    //printing the grid
    for(int j = 0; j < gui->field->get_len_y(); j++){
        for(int i = 0; i < gui->field->get_len_x(); i++){
            button = gtk_button_new();
            gtk_button_set_label(GTK_BUTTON(button), " ");
            s[i][j]->gui = gui;
            s[i][j]->box = gui->field->get_box_at(i, j);
            g_signal_connect(button, "button-press-event", G_CALLBACK(GraphicUserInterface::hit_target), s[i][j]);
            gtk_grid_attach(GTK_GRID(grid), button, i, j, 1, 1);
        }
    }

    gui->update_screen();
    gtk_widget_show_all(window);

    s.clear();
}

void GraphicUserInterface::hit_target(GtkWidget *btn, GdkEventButton *event, gpointer data) {
    GtkWidget *button;
    pass_struct *s = reinterpret_cast<pass_struct*>(data);
    GraphicUserInterface *gui = (GraphicUserInterface*) s->gui;
    Box *box = (Box*) s->box;

    //triggering the cascade or the marker
    if (event->type == GDK_BUTTON_PRESS && event->button == 1)
        gui->field->trigger_cascade(box->get_x(), box->get_y());
    else if(event->type == GDK_BUTTON_PRESS && event->button == 3)
        gui->field->mark(box->get_x(), box->get_y());
    gui->update_screen();

    //checking if winnig
    if(gui->field->get_status() == Field::STATUS_WIN)
        gui->win_display();
    if(gui->field->get_status() == Field::STATUS_LOSE)
        gui->lose_display();

}