#ifndef POSITION
#define POSITION
#include <iostream>
#include <math.h>
#include <cstring>
class Position {
    float x, y;
    public:
        Position(float init_x = 0, float init_y = 0);
        Position operator+(Position that);
        float operator-(const Position other);
        Position operator/(float denominator);
        void Read(std::istream &s);
        float GetX() const;
        float GetY() const;
};
#endif