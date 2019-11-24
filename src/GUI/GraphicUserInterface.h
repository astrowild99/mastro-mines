//
// Created by donato on 22/11/19.
//

#ifndef MINES_GRAPHICUSERINTERFACE_H
#define MINES_GRAPHICUSERINTERFACE_H


#include <gtk/gtk.h>
#include "../GameInterface.h"

class GraphicUserInterface : GameInterface {
private:
    GtkApplication *app;
    int gtk_window_id;

public:
    GraphicUserInterface(Player *player);
    GraphicUserInterface();

    void setup_new_game();
    Coordinates* input_coordinates();
    void update_screen();

    void win_display();
    void lose_display();

    int init_window(int argc, char **argv);

    int get_gtk_window_id();
    void set_gtk_window_id(int id);

    static void activate(GtkApplication *app, gpointer data);
    static void start_game(GtkApplication *app, gpointer data);

};


#endif //MINES_GRAPHICUSERINTERFACE_H
