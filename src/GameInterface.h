//
// Created by donato on 23/11/19.
//

#ifndef MINES_GAMEINTERFACE_H
#define MINES_GAMEINTERFACE_H


#include "Player.h"
#include "Field.h"

class GameInterface {
protected:
    Player *player;
    Field *field;
    time_t time_elapsed = 0;

    static const int PASS = 0;
    static const int ERROR = 1;
public:
    GameInterface(Player *player);
    GameInterface();

    int game_loop();

    virtual void setup_new_game() = 0;
    virtual Coordinates* input_coordinates() = 0;
    virtual void update_screen() = 0;

    virtual void win_display() = 0;
    virtual void lose_display() = 0;
};


#endif //MINES_GAMEINTERFACE_H
