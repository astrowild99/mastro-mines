#include <iostream>
#include <stdio.h>
#include "src/Field.h"

using namespace std;

int main() {
    Field *field = new Field(10, 10, 4);
    field->print();
    field->print_types();
    Box *arr = field->get_surr(0, 0);
    field->trigger_cascade(5, 5);
    field->print();
}