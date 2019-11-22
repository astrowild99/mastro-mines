//
// Created by donato on 22/11/19.
//

#include <string>
#include "Box.h"

Box::Box() {
    this->type = Box::EMPTY_TYPE;
}

Box::Box(int type) {
    this->type = type;
}

Box::Box(int type, int value) {
    this->type = type;
    this->value = value;
}

int Box::get_value() {
    return this->value;
}

Box Box::set_value(int value) {
    this->value = value;

    return *this;
}

bool Box::get_triggered() {
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
