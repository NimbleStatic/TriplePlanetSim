#ifndef STRUCTS_H
#define STRUCTS_H


struct Time{
    long double time;
};


struct Position{
    long double x;
    long double y;
    long double z;

    long double get_distance_from_pos(Position& value) const;
    Position operator+(const Position& other) const;
    Position& operator+=(const Position& other);
};

struct Force{
    long double x;
    long double y;
    long double z;

    Force operator+(const Force& other) const;
    Force& operator+=(const Force& other);
};

struct Velocity{
    long double x;
    long double y;
    long double z;
    Velocity operator+(const Velocity& other) const;
    Velocity& operator+=(const Velocity& other);
};

#endif
