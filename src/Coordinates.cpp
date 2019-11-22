//
// Created by donato on 22/11/19.
//

#include "Coordinates.h"

Coordinates::Coordinates() {
    this->x = 0;
    this->y = 0;
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
