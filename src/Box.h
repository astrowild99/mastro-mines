//
// Created by donato on 22/11/19.
//

#ifndef MINES_BOX_H
#define MINES_BOX_H


#include "Coordinates.h"

class Box {
private:
    int type, value;
    bool triggered;
public:
    Box();
    Box(int type);
    Box(int type, int value);

    int get_type();
    Box set_type(int type);
    int get_value();
    Box set_value(int value);
    bool get_triggered();
    char get_display();

    void set_mines_count(int count);
    void trigger();
    static const int EMPTY_TYPE = 0;
    static const int MINE_TYPE = 1;
    static const int NUMBER_TYPE = 2;
    static const char PLACEHOLDER_CHAR = ' ';
    static const char EMPTY_CHAR = '*';
    static const char MINE_CHAR = 'X';
};


#endif //MINES_BOX_H
