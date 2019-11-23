#include <iostream>
#include <stdio.h>
#include <gtk/gtk.h>
#include "src/Field.h"
#include "src/Player.h"
#include "src/CLI/CommandLineInterface.h"
#include "src/GUI/GraphicUserInterface.h"

using namespace std;

int main(int argc, char** argv) {
    gtk_init(&argc, &argv);
    GraphicUserInterface *gui = new GraphicUserInterface(argc, argv);
    Player *player = new Player();
    player->set_name("Donato");
    CommandLineInterface *interface = new CommandLineInterface(player);
    interface->setup_new_game();
    interface->game_loop();
    gui->setup_new_game();
}