//
// Created by donato on 22/11/19.
//

#include <string>
#include "Box.h"

Box::Box() {
    this->type = Box::EMPTY_TYPE;
    this->coordinates = new Coordinates();
}

Box::Box(int type) {
    this->type = type;
    this->coordinates = new Coordinates();
}

Box::Box(int type, Coordinates *coordinates) {
    this->type = type;
    this->coordinates = coordinates;
}

Box::Box(int type, int x, int y) {
    this->type = type;
    this->coordinates = new Coordinates(x, y);
}

Box::Box(Coordinates *coordinates) {
    this->coordinates = coordinates;
}

int Box::get_value() {
    return this->value;
}

Box Box::set_value(int value) {
    this->value = value;

    return *this;
}

bool Box::is_triggered() {
    return this->triggered;
}

int Box::get_type() {
    return this->type;
}

Box Box::set_type(int type) {
    this->type = type;

    return *this;
}

char Box::get_display() {
    if(!this->triggered)
        return Box::PLACEHOLDER_CHAR;
    if(this->type == Box::MINE_TYPE)
        return Box::MINE_CHAR;
    if(this->type == Box::EMPTY_TYPE)
        return Box::EMPTY_CHAR;
    return std::to_string(this->value)[0];
}

Coordinates* Box::get_coordinates() {
    return this->coordinates;
}

Box Box::set_coordinates(Coordinates *coordinates) {
    this->coordinates = coordinates;

    return *this;
}

Box Box::set_coordinates(int x, int y) {
    this->coordinates = new Coordinates(x, y);

    return *this;
}

void Box::set_mines_count(int count) {
    if(count > 0){
        this->set_value(count);
        this->set_type(Box::NUMBER_TYPE);
    }
}

void Box::trigger() {
    if(!this->triggered)
        this->triggered = true;
}

std::string Box::to_string() {
    return "" + coordinates->to_string() + " Value: " + std::to_string(this->value) + " type: " + std::to_string(this->type);
}
