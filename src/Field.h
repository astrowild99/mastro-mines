//
// Created by donato on 22/11/19.
//

#ifndef MINES_FIELD_H
#define MINES_FIELD_H


#include "Box.h"

class Field {
private:
    int len_x, len_y, mines = 0;
    Box **field_matrix;
    int count_mines(int x, int y);
    void update_count();
    int sanitize_x(int x);
    int sanitize_y(int y);
public:
    Field(int len_x, int len_y);
    Field(int len_x, int len_y, int mines);

    int get_len_x();
    int get_len_y();

    void trigger(int x, int y);

    void print();
    void print_types();
    void print_values();
};


#endif //MINES_FIELD_H
