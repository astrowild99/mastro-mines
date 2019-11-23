//
// Created by donato on 23/11/19.
//

#ifndef MINES_COMMANDLINEINTERFACE_H
#define MINES_COMMANDLINEINTERFACE_H


#include "../GameInterface.h"

class CommandLineInterface : public GameInterface {
public:
    CommandLineInterface();
    CommandLineInterface(Player *player);

    void setup_new_game() override;
    void update_screen() override;

    Coordinates* input_coordinates() override;

    void win_display() override;
    void lose_display() override;
};


#endif //MINES_COMMANDLINEINTERFACE_H
