//
// Created by donato on 22/11/19.
//

#include <string>
#include "Box.h"

Box::Box() {
    this->type = Box::EMPTY_TYPE;
    this->triggered = false;
    this->coordinates = new Coordinates();
}

Box::Box(int type) {
    this->type = type;
    this->triggered = false;
    this->coordinates = new Coordinates();
}

Box::Box(int type, Coordinates *coordinates) {
    this->type = type;
    this->triggered = false;
    this->coordinates = coordinates;
}

Box::Box(int type, int x, int y) {
    this->type = type;
    this->triggered = false;
    this->coordinates = new Coordinates(x, y);
}

Box::Box(Coordinates *coordinates) {
    this->coordinates = coordinates;
    this->triggered = false;
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

int Box::get_x() {
    return this->coordinates->get_x();
}

int Box::get_y() {
    return this->coordinates->get_y();
}

char Box::get_display() {
    if(this->marked)
        return Box::MARK_CHAR;
    if(!this->triggered)
        return Box::PLACEHOLDER_CHAR;
    if(this->type == Box::MINE_TYPE)
        return Box::MINE_CHAR;
    if(this->type == Box::EMPTY_TYPE)
        return Box::EMPTY_CHAR;
    return std::to_string(this->value)[0];
}

std::string Box::get_string_display() {
    std::string string(1, this->get_display());
    return string;
}

std::string Box::get_string_triggered() {
    std::string string;
    string.append(std::to_string(this->is_triggered()));
    return string;
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

Box Box::set_triggered(bool triggered) {
    this->triggered = triggered;
    return *this;
}

bool Box::is_marked() {
    return this->marked;
}

Box Box::set_marked(bool marked) {
    this->marked = marked;

    return *this;
}

bool Box::mark() {
    this->marked = !this->marked;

    return this->marked;
}

std::string Box::to_string() {
    return "" + coordinates->to_string() + " Value: " + std::to_string(this->value) + " type: " + std::to_string(this->type);
}
