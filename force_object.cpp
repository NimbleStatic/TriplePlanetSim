#include "force_object.h"

Force_Object::Force_Object(long double mass, long double size, Position position):mass(mass), size(size), curr_positon(position)
{
    curr_forces = {0,0,0};
    curr_velocity = {0,0,0};

}

void Force_Object::set_force(long double Fx, long double Fy, long double Fz)
{
    curr_forces = {Fx,Fy,Fz};
}

void Force_Object::add_force(long double Fx, long double Fy, long double Fz)
{
    curr_forces.x  = curr_forces.x + Fx;
    curr_forces.y = curr_forces.y + Fy;
    curr_forces.z = curr_forces.z + Fz;
}

void Force_Object::set_velocity(long double Vx, long double Vy, long double Vz)
{
}

void Force_Object::add_velocity(long double Vx, long double Vy, long double Vz)
{
}

void Force_Object::set_force(Force value)
{
}

void Force_Object::add_force(Force value)
{
}

void Force_Object::set_velocity(Velocity value)
{
}

void Force_Object::add_velocity(Velocity value)
{
}

void Force_Object::move_in_time(Time moving_time)
{
}

long double Force_Object::get_mass() const
{
    return mass;
}

long double Force_Object::get_size() const
{
    return size;
}

Position Force_Object::get_curr_pos() const
{
    return curr_positon;
}

std::vector<std::tuple<Position, Time>> Force_Object::get_pos_history() const
{
    return pos_history;
}
