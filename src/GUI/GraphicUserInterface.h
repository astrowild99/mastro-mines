//
// Created by donato on 22/11/19.
//

#ifndef MINES_GRAPHICUSERINTERFACE_H
#define MINES_GRAPHICUSERINTERFACE_H


#include <gtk/gtk.h>
#include "../GameInterface.h"

class GraphicUserInterface : GameInterface {
private:
    int argc;
    char** argv;

public:
    GraphicUserInterface(Player *player);
    GraphicUserInterface();

    ~GraphicUserInterface();

    void setup_new_game();
    Coordinates* input_coordinates();
    void update_screen();
    void reveal_screen();

    void win_display();
    void lose_display();

    int init_window(int argc, char **argv);

    static void activate(GtkApplication *app, gpointer data);
    static void start_game(GtkApplication *app, gpointer data);
    static void hit_target(GtkWidget *btn, GdkEventButton *event, gpointer data);

};


#endif //MINES_GRAPHICUSERINTERFACE_H
