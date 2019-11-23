//
// Created by donato on 23/11/19.
//

#ifndef MINES_PLAYER_H
#define MINES_PLAYER_H


#include <string>

class Player {
private:
    int id;
    std::string name = "Player";
    int game_status = Player::STATUS_PLAYING;
protected:
    static Player **players_array;
    static int players_array_count;
    static int last_used_id;
public:
    static const int STATUS_PLAYING = 0;
    static const int STATUS_LOST = 1;
    static const int STATUS_PAUSE = 2;

    Player();

    std::string to_string();

    int get_id();
    Player *set_status(int status);
    int get_status();
    Player *set_name(std::string name);
    std::string get_name();

    static Player *get_by_id(int id);
    static void add_new(Player *player);
};


#endif //MINES_PLAYER_H
