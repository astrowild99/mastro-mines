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
    GtkWidget *window;
    GtkWidget *start_button;

    int status;
public:
    GraphicUserInterface(GtkApplication* app, Player *player);
    GraphicUserInterface(GtkApplication* app);

    void setup_new_game();
    Coordinates* input_coordinates();
    void update_screen();

    void win_display();
    void lose_display();

};


#endif //MINES_GRAPHICUSERINTERFACE_H
