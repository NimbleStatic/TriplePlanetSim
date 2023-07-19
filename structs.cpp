#include "structs.h"
#include "cmath"

long double Position::get_distance_from_pos(Position &value) const{
    long double r_x = pow((this->x - value.x),2);
    long double r_y = pow((this->y - value.y),2);
    long double r_z = pow((this->z - value.z),2);
    return std::sqrt(r_x+r_y+r_z);
};
