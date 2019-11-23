//
// Created by donato on 23/11/19.
//

#ifndef MINES_COMMANDLINEINTERFACE_H
#define MINES_COMMANDLINEINTERFACE_H


#include "../GameInterface.h"

class CommandLineInterface : public GameInterface {
public:
    CommandLineInterface();

    void setup_new_game() override;
    void update_screen() override;

    virtual Coordinates* input_coordinates() override;
};


#endif //MINES_COMMANDLINEINTERFACE_H
