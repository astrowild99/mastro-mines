//
// Created by donato on 22/11/19.
//

#ifndef MINES_COORDINATES_H
#define MINES_COORDINATES_H


class Coordinates {
private:
    int x, y;
public:
    Coordinates();
    Coordinates(int x, int y);

    int get_x();
    int get_y();
    Coordinates set_x(int x);
    Coordinates set_y(int y);

};


#endif //MINES_COORDINATES_H
