//
// Created by donato on 22/11/19.
//

#include "GraphicUserInterface.h"
#include <gtk/gtk.h>

static GtkEntryBuffer *buffer_x = NULL, *buffer_y = NULL, *buffer_mines = NULL;

GraphicUserInterface::GraphicUserInterface() : GraphicUserInterface(new Player()) {}

GraphicUserInterface::GraphicUserInterface(Player *player){
    this->player = player;
}

void GraphicUserInterface::setup_new_game() {

}

Coordinates* GraphicUserInterface::input_coordinates() {
    return new Coordinates();
}

void GraphicUserInterface::update_screen() {

}

void GraphicUserInterface::win_display() {

}

void GraphicUserInterface::lose_display() {

}

int GraphicUserInterface::init_window(int argc, char **argv) {
    int status;

    app = gtk_application_new("mines.donato.com", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(GraphicUserInterface::activate), this);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

void GraphicUserInterface::activate(GtkApplication *app, gpointer data) {
    GtkWidget *window;
    GtkWidget *button_box;
    GtkWidget *start_button;
    GtkWidget *box;
    GtkWidget *label_x, *label_y, *label_mines;
    GtkWidget *entry_x, *entry_y, *entry_mines;
    GraphicUserInterface *gui = (GraphicUserInterface*) data;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Mines");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
    gui->set_gtk_window_id(gtk_application_window_get_id(GTK_APPLICATION_WINDOW(window)));

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

    button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add(GTK_CONTAINER(box), button_box);

    start_button = gtk_button_new_with_label("Start");
    g_signal_connect(start_button, "clicked", G_CALLBACK(GraphicUserInterface::start_game), gui);
    gtk_container_add(GTK_CONTAINER(button_box), start_button);
    gtk_widget_show_all(window);
}

void GraphicUserInterface::start_game(GtkApplication *app, gpointer data) {
    GraphicUserInterface *gui = (GraphicUserInterface*) data;
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *grid;
    GtkWidget *button;

    //setting up the game
    gui->field = new Field(
            atoi(gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(buffer_x))),
            atoi(gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(buffer_y))),
            atoi(gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(buffer_mines)))
            );

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    gtk_window_set_title(GTK_WINDOW(window), "Actual Game");

    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);
    gtk_container_add(GTK_CONTAINER(window), box);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(box), grid);

    //printing the grid
    for(int j = 0; j < gui->field->get_len_y(); j++){
        for(int i = 0; i < gui->field->get_len_x(); i++){
            button = gtk_button_new();
            gtk_button_set_label(GTK_BUTTON(button), gui->field->get_box_at(i, j)->get_string_display().c_str());

            gtk_grid_attach(GTK_GRID(grid), button, i, j, 1, 1);
        }
    }

    gtk_widget_show_all(window);

}

void GraphicUserInterface::set_gtk_window_id(int id) {
    this->gtk_window_id = id;
}

int GraphicUserInterface::get_gtk_window_id() {
    return this->gtk_window_id;
}