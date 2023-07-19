#ifndef PLANET_OBJECT_H
#define PLANET_OBJECT_H
#include "structs.h"
#include"vector"
#include"tuple"

class Force_Object{
    private:
        long double mass;
        long double size;
        Position curr_positon;
        Force curr_forces;
        Velocity curr_velocity;
        std::vector<std::tuple<Position,Time>> pos_history;
    public:
        Force_Object(long double mass, long double size, Position position);
        void set_force(long double Fx, long double Fy, long double Fz);
        void add_force(long double Fx, long double Fy, long double Fz);
        void set_velocity(long double Vx, long double Vy, long double Vz);
        void add_velocity(long double Vx, long double Vy, long double Vz);
        void set_force(Force value);
        void add_force(Force value);
        void set_velocity(Velocity value);
        void add_velocity(Velocity value);
        void move_in_time(Time moving_time);
        long double get_mass() const;
        long double get_size() const;
        Position get_current_pos() const;
        std::vector<std::tuple<Position,Time>> get_pos_history() const;

};

#endif