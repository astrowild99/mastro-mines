//
// Created by donato on 23/11/19.
//

#include "Player.h"

int Player::players_array_count = 0;

Player** Player::players_array = {};

int Player::last_used_id = 0;

Player::Player() {
    this->id = Player::last_used_id;
    Player::last_used_id += 1;

    Player::add_new(this);
}

void Player::add_new(Player *player) {
    if(Player::players_array_count == 0) {
        Player::players_array = (Player **) malloc(sizeof(Player *));
        Player::players_array[players_array_count] = player;
    }
    else{
        Player::players_array = (Player**) realloc(Player::players_array, Player::players_array_count * sizeof(Player*));
        Player::players_array[players_array_count] = player;
    }
    Player::players_array_count += 1;
}

Player* Player::get_by_id(int id) {
    for(int i = 0; i < Player::players_array_count; i++){
        if(Player::players_array[i]->get_id() == id)
            return Player::players_array[i];
    }
    return new Player();
}

int Player::get_id() {
    return this->id;
}

Player* Player::set_name(std::string name) {
    this->name = name;

    return this;
}

std::string Player::get_name(){
    return this->name;
}

int Player::get_status() {
    return this->game_status;
}

Player* Player::set_status(int status) {
    this->game_status = status;

    return this;
}

std::string Player::to_string() {
    return " " + std::to_string(this->get_id()) + "| " + this->get_name();
}
