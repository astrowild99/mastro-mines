//
// Created by donato on 22/11/19.
//

#include <string>
#include "Coordinates.h"

Coordinates::Coordinates() {
    this->x = -1;
    this->y = -1;
}

Coordinates::Coordinates(int x, int y) {
    this->x = x;
    this->y = y;
}

int Coordinates::get_x() {
    return this->x;
}

int Coordinates::get_y() {
    return this->y;
}

Coordinates Coordinates::set_x(int x) {
    this->x = x;

    return *this;
}

Coordinates Coordinates::set_y(int y) {
    this->y = y;

    return *this;
}

Coordinates Coordinates::set(int x, int y){
    this->x = x;
    this->y = y;

    return *this;
}

int* Coordinates::get() {
    int *array = new int[2];

    array[0] = this->x;
    array[1] = this->y;

    return array;
}

std::string Coordinates::to_string() {
    return "(" + std::to_string(this->x) + ";" + std::to_string(this->y) + ")";
}

bool Coordinates::is_zero() {
    if(this->x == 0 && this->y == 0)
        return true;
    return false;
}

bool Coordinates::is_valid() {
    return this->x > 0 && this->y > 0;
}
