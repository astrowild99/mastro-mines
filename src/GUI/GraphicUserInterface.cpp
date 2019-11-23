//
// Created by donato on 22/11/19.
//

#include "GraphicUserInterface.h"
#include <gtk/gtk.h>

GraphicUserInterface::GraphicUserInterface(GtkApplication* app) : GraphicUserInterface(app, new Player()) {}

GraphicUserInterface::GraphicUserInterface(GtkApplication* app, Player *player){
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