//
// Created by donato on 22/11/19.
//

#include <stdio.h>
#include <iostream>
#include <gtk/gtk.h>
#include "Field.h"
#include "Coordinates.h"

Field::Field(int len_x, int len_y) {
    this->len_x = len_x;
    this->len_y = len_y;

    //creating the matrix
    field_matrix.resize(len_x);
    for(int j = 0; j < len_x; j++){
        field_matrix[j].resize(len_y);
    }

    for(int j = 0; j < len_y; j++){
        for(int i = 0; i < len_x; i++){
            field_matrix[i][j] = new Box(Box::EMPTY_TYPE, i, j);
            g_print("%s\n", field_matrix[i][j]->to_string().c_str());
        }
    }

    //and getting the coordinates ready
    for(int j = 0; j < len_y; j++){
        for(int i = 0; i < len_x; i++){
            this->field_matrix[i][j]->set_coordinates(new Coordinates(i, j));
            this->field_matrix[i][j]->set_triggered(false);
        }
    }

    g_print("FIELD CREATED\n");
}

Field::Field(int len_x, int len_y, int mines) : Field::Field(len_x, len_y){
    this->mines = mines;
    this->missing = mines;

    srand(time(NULL));

    //placing the mines
    int x, y;
    for(int i = 0; i < mines; i++){
        x = rand() % this->len_x;
        y = rand() % this->len_y;
        if(this->field_matrix[x][y]->get_type() != Box::EMPTY_TYPE){
            i--;
            continue;
        }
        field_matrix[x][y]->set_type(Box::MINE_TYPE);
    }

    this->update_count();
}

Field::Field() : Field(Field::STD_X, Field::STD_Y, Field::STD_MINES){}

Field::~Field() {
    this->field_matrix.clear();
    g_print("FIELD DELETED\n");
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
            printf(" %c", this->field_matrix[i][j]->get_display());
        }
        printf("\n");
    }
}

void Field::print_types() {
    for(int j = 0; j < this->len_y; j++){
        for(int i = 0; i < this->len_x; i++){
            printf(" %d", this->field_matrix[i][j]->get_type());
        }
        printf("\n");
    }
}

void Field::print_values() {
    for(int j = 0; j < this->len_y; j++){
        for(int i = 0; i < this->len_x; i++){
            printf(" %d", this->field_matrix[i][j]->get_value());
        }
        printf("\n");
    }
}

Box* Field::trigger(Coordinates *coordinates) {
    this->field_matrix[coordinates->get_x()][coordinates->get_y()]->trigger();

    return this->field_matrix[coordinates->get_x()][coordinates->get_y()];
}

Box* Field::trigger(int x, int y) {
    this->field_matrix[x][y]->trigger();

    return this->field_matrix[x][y];
}

Box* Field::mark(int x, int y) {
    bool is_mark = this->field_matrix[x][y]->mark();
    if(is_mark)
        this->missing -= 1;
    else
        this->missing += 1;
    return this->field_matrix[x][y];
}

Box* Field::trigger(Box *box) {
    int x = box->get_coordinates()->get_x();
    int y = box->get_coordinates()->get_y();
    this->field_matrix[x][y]->trigger();

    return this->field_matrix[x][y];
}

int Field::count_mines(int x, int y) {
    int box_start_x, box_start_y, box_end_x, box_end_y, count = 0;
    box_start_x = this->sanitize_x(x - 1);
    box_start_y = this->sanitize_y(y - 1);
    box_end_x = this->sanitize_x(x + 1);
    box_end_y = this->sanitize_y(y + 1);

    for(int j = box_start_y; j <= box_end_y; j++){
        for(int i = box_start_x; i <= box_end_x; i++){
            if(this->field_matrix[i][j]->get_type() == Box::MINE_TYPE) {
                count++;
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
            if(this->field_matrix[i][j]->get_type() != Box::MINE_TYPE) {
                field_matrix[i][j]->set_mines_count(count_mines(i, j));
            }
        }
    }
}

Box* Field::get_box_at(int x, int y){
    return this->field_matrix[x][y];
}

Box* Field::get_box_at(Coordinates *coordinates) {
    return this->get_box_at(coordinates->get_x(), coordinates->get_y());
}

std::vector<Box*> Field::get_surr(Coordinates *coordinates) {
    std::vector<Box*> surr;
    int x = coordinates->get_x(), y = coordinates->get_y();
    int box_start_x, box_start_y, box_end_x, box_end_y, count = 0;
    box_start_x = this->sanitize_x(x - 1);
    box_start_y = this->sanitize_y(y - 1);
    box_end_x = this->sanitize_x(x + 1);
    box_end_y = this->sanitize_y(y + 1);

    for(int j = box_start_y; j <= box_end_y; j++){
        for(int i = box_start_x; i <= box_end_x; i++){
            if((i != x) || (j != y)) {
                surr.push_back(this->field_matrix[i][j]);
            }
        }
    }
    return surr;
}

std::vector<Box*> Field::get_surr(int x, int y) {
    Coordinates *coordinates = new Coordinates(x, y);
    return this->get_surr(coordinates);
}

int Field::get_surr_triggered(Coordinates *coordinates) {
    std::vector<Box*> array = this->get_surr(coordinates);
    int count = 0;
    for(int i = 0; i < array.size(); i++){
        if(array[i] == NULL)
            continue;
        if(array[i] != NULL && array[i]->get_type() == Box::EMPTY_TYPE && array[i]->is_triggered()) {
            count += 1;
        }
    }
    return count;
}

int Field::get_surr_triggered(int x, int y) {
    Coordinates *coordinates = new Coordinates(x, y);
    return this->get_surr_triggered(coordinates);
}

int Field::get_missing() {
    return this->missing;
}

void Field::trigger_cascade(Coordinates *coordinates) {
    this->trigger(coordinates);

    if(!this->get_box_at(coordinates)->get_type() == Box::EMPTY_TYPE)
        return;

    //optimize this shit
    bool go_on = true;
    while(go_on){
        go_on = false;
        for(int j = 0; j < this->get_len_y(); j++){
            for(int i = 0; i < this->get_len_x(); i++){
                int surr = this->get_surr_triggered(i, j);
                if(surr > 0){
                    if(
                            this->field_matrix[i][j]->get_type() != Box::MINE_TYPE &&
                            !this->field_matrix[i][j]->is_triggered()
                            ){
                        go_on = true;
                        this->field_matrix[i][j]->trigger();
                    }
                }
            }
        }
    }
}

void Field::trigger_cascade(int x, int y) {
    Coordinates *coordinates = new Coordinates(x, y);

    return this->trigger_cascade(coordinates);
}

int Field::get_status() {
    this->update_status();
    return this->status;
}

void Field::update_status() {
    bool is_empty = true;
    for(int j = 0; j < this->len_y; j++){
        for(int i = 0; i < this->len_x; i++){
            if(this->field_matrix[i][j]->is_triggered()){
                if(this->field_matrix[i][j]->get_type() == Box::MINE_TYPE) {
                    this->status = STATUS_LOSE;
                    return;
                }
            }
            else if(!this->field_matrix[i][j]->is_marked()){
                is_empty = false;
            }
        }
    }
    if(is_empty)
        this->status = Field::STATUS_WIN;
}

std::string Field::to_string() {
    std::string string;
    for(int j = 0; j < this->len_y; j++){
        for(int i = 0; i < this->len_x; i++){
            string.append(std::to_string(this->field_matrix[i][j]->get_type()));
        }
        string.append("\n");
    }
    return string;
}