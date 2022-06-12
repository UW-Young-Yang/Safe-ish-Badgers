#include "Position.h"

Position::Position(float init_x, float init_y) {
    x = init_x;
    y = init_y;
}

Position Position::operator+(Position that) {
    float new_x = x + that.x;
    float new_y = y + that.y;
    return Position(new_x, new_y);
}

float Position::operator-(const Position other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

Position Position::operator/(float denominator) {
    float new_x = x / denominator;
    float new_y = y / denominator;
    return Position(new_x, new_y);
}

void Position::Read(std::istream &s) {
    char data[1024];
    s.getline(data, '\n');
    x = std::stof(std::strtok(data, " "));
    y = std::stof(std::strtok(NULL, " "));
    //scanf("%f %f", x, y);
}

float Position::GetX() const {
    return x;
}

float Position::GetY() const {
    return y;
}