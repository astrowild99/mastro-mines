//
// Created by donato on 22/11/19.
//

#include <stdio.h>
#include <iostream>
#include "Field.h"

Field::Field(int len_x, int len_y) {
    this->len_x = len_x;
    this->len_y = len_y;

    //creating the matrix
    this->field_matrix = new Box*[len_y];
    for(int i = 0; i < len_x; i++)
        this->field_matrix[i] = new Box[len_x];
}

Field::Field(int len_x, int len_y, int mines) : Field::Field(len_x, len_y){
    this->mines = mines;

    srand(time(NULL));

    //placing the mines
    int x, y;
    for(int i = 0; i < mines; i++){
        x = rand() % this->len_x;
        y = rand() % this->len_y;
        if(this->field_matrix[x][y].get_type() != Box::EMPTY_TYPE){
            i--;
            continue;
        }
        field_matrix[x][y].set_type(Box::MINE_TYPE);
    }

    this->update_count();
}

int Field::get_len_x() {
    return this->len_x;
}

int Field::get_len_y() {
    return this->len_y;
}

void Field::print() {
    for(int j = 0; j < this->len_y; j++){
        for(int i = 0; i < this->len_x; i++){
            printf(" %c", this->field_matrix[i][j].get_display());
        }
        printf("\n");
    }
}

void Field::print_types() {
    for(int j = 0; j < this->len_y; j++){
        for(int i = 0; i < this->len_x; i++){
            printf(" %d", this->field_matrix[i][j].get_type());
        }
        printf("\n");
    }
}

void Field::print_values() {
    for(int j = 0; j < this->len_y; j++){
        for(int i = 0; i < this->len_x; i++){
            printf(" %d", this->field_matrix[i][j].get_value());
        }
        printf("\n");
    }
}

void Field::trigger(int x, int y) {
    this->field_matrix[x][y].trigger();
}

int Field::count_mines(int x, int y) {
    int box_start_x, box_start_y, box_end_x, box_end_y, count = 0;
    box_start_x = this->sanitize_x(x - 1);
    box_start_y = this->sanitize_y(y - 1);
    box_end_x = this->sanitize_x(x + 1);
    box_end_y = this->sanitize_y(y + 1);

    for(int j = box_start_y; j <= box_end_y; j++){
        for(int i = box_start_x; i <= box_end_x; i++){
            if(this->field_matrix[i][j].get_type() == Box::MINE_TYPE) {
                count++;
                printf("\t\tDEBUG: !!!!!!!!!!!mine found!!!!!!!!!!!\n");
            }
        }
    }
    return count;
}

int Field::sanitize_x(int x) {
    if(x < 0)
        return 0;
    if(x > (this->len_x - 1))
        return (this->len_x - 1);
    return x;
}

int Field::sanitize_y(int y) {
    if(y < 0)
        return 0;
    if(y > (this->len_y - 1))
        return (this->len_y - 1);
    return y;
}

void Field::update_count() {
    for(int j = 0; j < len_y; j++){
        for(int i = 0; i < len_x; i++){
            if(this->field_matrix[i][j].get_type() != Box::MINE_TYPE) {
                field_matrix[i][j].set_mines_count(count_mines(i, j));
            }
        }
    }
}
