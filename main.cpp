#include <iostream>
#include <stdio.h>
#include "src/Field.h"
#include "src/Player.h"
#include "src/CLI/CommandLineInterface.h"

using namespace std;

int main() {
    Field *field = new Field(10, 10, 8);
    Player *pippo = new Player();
    Player *pluto = new Player();
    CommandLineInterface *interface = new CommandLineInterface();
    pippo->set_name("Pippo");
    pluto->set_name("Pluto");
    std::cout << Player::get_by_id(0)->to_string() << std::endl;
    field->print();
    field->print_types();
    Box *arr = field->get_surr(0, 0);
    field->trigger_cascade(5, 5);
    field->print();
    interface->setup_new_game();
    interface->game_loop();


}