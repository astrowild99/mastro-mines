//
// Created by donato on 23/11/19.
//

#include "CommandLineInterface.h"

CommandLineInterface::CommandLineInterface() : GameInterface() {
    printf(" . . . Starting a new Game . . . \n");
}

void CommandLineInterface::setup_new_game(){
    int x, y, m;
    printf("\nInput field size: x,y,mines: ");
    scanf("%d,%d,%d", &x, &y, &m);
    this->field = new Field(x, y, m);
}

Coordinates* CommandLineInterface::input_coordinates() {
    int x, y;
    printf("\nHit a target: x,y");
    scanf("%d,%d", &x, &y);
    return new Coordinates(x, y);
}

void CommandLineInterface::update_screen() {
    this->field->print();
}
