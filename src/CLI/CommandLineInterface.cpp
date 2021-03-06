//
// Created by donato on 23/11/19.
//

#include "CommandLineInterface.h"

CommandLineInterface::CommandLineInterface(int argc, char** argv) : GameInterface() {
    printf(" . . . Starting a new Game . . . \n");
}

CommandLineInterface::CommandLineInterface(int argc, char** argv, Player *player) : GameInterface() {
    this->player = player;
}

void CommandLineInterface::setup_new_game(){
    int x, y, m;
    printf("\nInput field size: x,y,mines: ");
    scanf("%d,%d,%d", &x, &y, &m);
    this->field = new Field(x, y, m);
}

Coordinates* CommandLineInterface::input_coordinates() {
    int x, y;
    printf("\nHit a target: x,y:\n");
    scanf("%d,%d", &x, &y);
    return new Coordinates(x, y);
}

void CommandLineInterface::update_screen() {
    this->field->print();
}

void CommandLineInterface::win_display() {
    printf("\n . . . WIN . . .\n");
}

void CommandLineInterface::lose_display() {
    printf("\n . . . LOSE . . .\n");
}
