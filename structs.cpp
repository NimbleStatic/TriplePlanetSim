#include "structs.h"
#include "cmath"

long double Position::get_distance_from_pos(Position &value) const{
    long double r_x = pow((this->x - value.x),2);
    long double r_y = pow((this->y - value.y),2);
    long double r_z = pow((this->z - value.z),2);
    return std::sqrt(r_x+r_y+r_z);
};


Velocity Velocity::operator+(const Velocity& other) const {
    Velocity result;
    result.x = x + other.x;
    result.y = y + other.y;
    result.z = z + other.z;
    return result;
}


Velocity& Velocity::operator+=(const Velocity& other) {
    *this = *this + other;
    return *this;
}

Position Position::operator+(const Position& other) const {
    Position result;
    result.x = x + other.x;
    result.y = y + other.y;
    result.z = z + other.z;
    return result;
}


Position& Position::operator+=(const Position& other) {
    *this = *this + other;
    return *this;
}

Force Force::operator+(const Force& other) const {
    Force result;
    result.x = x + other.x;
    result.y = y + other.y;
    result.z = z + other.z;
    return result;
}


Force& Force::operator+=(const Force& other) {
    *this = *this + other;
    return *this;
}

