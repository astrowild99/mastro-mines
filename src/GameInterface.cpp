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
    this->update_screen();
    while(is_playing){
        field->trigger_cascade(this->input_coordinates());
        this->update_screen();
        field->update_status();
        is_playing = field->get_status() == Field::STATUS_PLAYING;
    }
    if(field->get_status() == Field::STATUS_WIN)
        this->win_display();
    if(field->get_status() == Field::STATUS_LOSE)
        this->lose_display();
}