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
        if(input == TAG_CLI){
            CommandLineInterface *cli = new CommandLineInterface(argc, argv);
            cli->setup_new_game();
            cli->game_loop();
            return 0;
        }
    }
    gtk_init(&argc, &argv);
    GraphicUserInterface *gui = new GraphicUserInterface(argc, argv);
    gui->setup_new_game();
    return 0;
}