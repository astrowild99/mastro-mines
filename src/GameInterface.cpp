//
// Created by donato on 23/11/19.
//

#include "GameInterface.h"

GameInterface::GameInterface() : GameInterface(new Player()) {};

GameInterface::GameInterface(Player *player) {
    this->player = player;
}

int GameInterface::game_loop() {
    bool is_playing = true;
    while(is_playing){
        field->trigger_cascade(this->input_coordinates());
        this->update_screen();
        field->update_status();
        is_playing = field->get_status() == Field::STATUS_PLAYING;
    }
}

Coordinates* GameInterface::input_coordinates() {};
