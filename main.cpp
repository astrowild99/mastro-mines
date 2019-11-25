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
            int a = 1;
            CommandLineInterface *cli = new CommandLineInterface(argc, argv);
            while(a){
                cli->setup_new_game();
                cli->game_loop();
                std::cout << "Continuare?" << std::endl;
                std::cin >> a;
            }
            return 0;
        }
    }
//    gtk_init(&argc, &argv);
    GraphicUserInterface *gui = new GraphicUserInterface();
    gui->init_window(argc, argv);
    return 0;
}