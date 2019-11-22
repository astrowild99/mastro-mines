#include <iostream>
#include <stdio.h>
#include "src/Field.h"

using namespace std;

int main() {
    Field *field = new Field(10, 10, 4);
    field->print();
    for(int j = 0; j < field->get_len_y(); j++){
        for(int i = 0; i < field->get_len_x(); i++){
            field->trigger(i, j);
        }
    }
    field->print();
    printf("Hello World");
}