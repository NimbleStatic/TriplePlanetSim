#include "force_object.h"
#include <cmath>
#include "structs.h"
#include"vector"
#include"tuple"

Force_Object::Force_Object(long double mass, long double size, Position position):mass(mass), size(size), curr_positon(position)
{
    curr_forces = {0,0,0};
    curr_velocity = {0,0,0};
    curr_time = {0};
    pos_history.push_back(std::tuple(position,Time {0}));

}

void Force_Object::set_force(long double Fx, long double Fy, long double Fz)
{
    this->set_force({Fx,Fy,Fz});
}

void Force_Object::add_force(long double Fx, long double Fy, long double Fz)
{
    this->add_force({Fx,Fy,Fz});
}

void Force_Object::set_velocity(long double Vx, long double Vy, long double Vz)
{
    this->set_velocity({Vx,Vy,Vz});
}

void Force_Object::add_velocity(long double Vx, long double Vy, long double Vz)
{
    this->add_velocity({Vx,Vy,Vz});
}

void Force_Object::set_force(Force value)
{
    curr_forces = value;
}

void Force_Object::add_force(Force value)
{
    curr_forces += value;
}

void Force_Object::set_velocity(Velocity value)
{
    curr_velocity = value;
}

void Force_Object::add_velocity(Velocity value)
{
    curr_velocity += value;
}

void Force_Object::move_in_time(Time value)
{
    curr_positon.x = curr_velocity.x*value.time + ((curr_forces.x/mass)*std::pow(value.time, 2))/2;
    curr_positon.y = curr_velocity.y*value.time + ((curr_forces.y/mass)*std::pow(value.time, 2))/2;
    curr_positon.z = curr_velocity.z*value.time + ((curr_forces.z/mass)*std::pow(value.time, 2))/2;

    curr_velocity.x = curr_velocity.x + ((curr_forces.x/mass)*value.time);
    curr_velocity.y = curr_velocity.y + ((curr_forces.y/mass)*value.time);
    curr_velocity.z = curr_velocity.z + ((curr_forces.z/mass)*value.time);

    curr_time.time += value.time;

    pos_history.push_back(std::tuple(curr_positon, curr_time));

}

long double Force_Object::get_mass() const
{
    return mass;
}

long double Force_Object::get_size() const
{
    return size;
}

Position Force_Object::get_current_pos() const
{
    return curr_positon;
}

Velocity Force_Object::get_current_velocity() const
{
    return curr_velocity;
}

std::vector<std::tuple<Position, Time>> Force_Object::get_pos_history() const
{
    return pos_history;
}
