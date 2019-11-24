#include <iostream>
#include <stdio.h>
#include <gtk/gtk.h>
#include "src/Field.h"
#include "src/Player.h"
#include "src/CLI/CommandLineInterface.h"
#include "src/GUI/GraphicUserInterface.h"

#define TAG_CLI "-cli"

using namespace std;

int main(int argc, char** argv) {
    //the tag for the cli is -cli
    if(argc > 1){
        std::string input(argv[1]);
        if(!input.compare(TAG_CLI)){
            CommandLineInterface *cli = new CommandLineInterface(argc, argv);
            cli->setup_new_game();
        }
    }
    gtk_init(&argc, &argv);
    GraphicUserInterface *gui = new GraphicUserInterface(argc, argv);
    gui->setup_new_game();
//    gui->init_window(argc, argv);
//    gui->setup_new_game();
//    Player *player = new Player();
//    player->set_name("Donato");
//    CommandLineInterface *interface = new CommandLineInterface(player);
//    interface->setup_new_game();
//    interface->game_loop();
//    gui->setup_new_game();
}