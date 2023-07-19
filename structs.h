#ifndef STRUCTS_H
#define STRUCTS_H

struct Time{
    long double time;
};


struct Position{
    long double x;
    long double y;
    long double z;

    long double get_distance_from_pos(Position &value) const;
};

#endif
