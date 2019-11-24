//
// Created by donato on 22/11/19.
//

#ifndef MINES_BOX_H
#define MINES_BOX_H


#include "Coordinates.h"

class Box {
private:
    int type, value;
    bool triggered = false;
    bool marked = false;
    Coordinates *coordinates;

public:
    Box();
    Box(Coordinates *coordinates);
    Box(int type);
    Box(int type, Coordinates *coordinates);
    Box(int type, int x, int y);
    ~Box();

    std::string to_string();

    int get_type();
    Box set_type(int type);
    int get_value();
    Box set_value(int value);
    Coordinates *get_coordinates();
    int get_x();
    int get_y();
    Box set_coordinates(Coordinates *coordinates);
    Box set_coordinates(int x, int y);
    Box set_triggered(bool triggered);
    bool is_triggered();
    Box set_marked(bool marked);
    bool is_marked();
    bool mark();
    char get_display();
    std::string get_string_display();
    std::string get_string_triggered();

    void set_mines_count(int count);
    void trigger();

    static const int EMPTY_TYPE = 0;
    static const int MINE_TYPE = 1;
    static const int NUMBER_TYPE = 2;
    static const char PLACEHOLDER_CHAR = '*';
    static const char EMPTY_CHAR = ' ';
    static const char MINE_CHAR = 'X';
    static const char MARK_CHAR = 'P';
};


#endif //MINES_BOX_H
