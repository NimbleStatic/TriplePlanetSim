#include "gravity_system.h"
#include"algorithm"
#include "iostream"

Gravity_System::Gravity_System(Time time_step) : time_step(time_step), full_time({0}), g_const(1) {}

bool Gravity_System::add_object(std::unique_ptr<Force_Object> new_object) {
    if (new_object) {
        active_objects.push_back(std::move(new_object));
        return true;
    }
    return false;
}

void Gravity_System::simulate_system(Time time_to_sim){
    while (time_to_sim.time > full_time.time){
        this->update_system();
    };
}

bool Gravity_System::delete_object_by_id(unsigned id) {
    auto it = std::remove_if(active_objects.begin(), active_objects.end(),
                             [id](const std::unique_ptr<Force_Object>& obj) {
                                 return obj->get_object_id() == id;
                             });

    if (it != active_objects.end()) {
        active_objects.erase(it, active_objects.end());
        return true;
    }

    return false;
}

void Gravity_System::update_system(Time step) {
    update_gravity_forces();

    for (auto& object : active_objects) {
        object->move_in_time(step);
    }
    full_time.time += step.time;
}

void Gravity_System::update_system() {
    update_system(time_step);
}

void Gravity_System::update_gravity_forces() {
    for (size_t i = 0; i < active_objects.size(); ++i) {
        active_objects[i]->set_force({0,0,0});
        long double mass1 = active_objects[i]->get_mass();
        Position pos1 = active_objects[i]->get_current_pos();
        for (size_t j = 0; j < active_objects.size(); ++j) {
            if (j == i){
                break;
            }
            long double mass2 = active_objects[j]->get_mass();
            Position pos2 = active_objects[j]->get_current_pos();

            long double rx = pos2.x-pos1.x;
            long double ry = pos2.y-pos1.y;
            long double rz = pos2.z-pos1.z;

            long double gmm = g_const*mass1*mass2;

            Force new_force = {gmm/(rx*abs(rx)), gmm/(ry*abs(ry)), gmm/(rz*abs(rz))};

            active_objects[i]->add_force(new_force);
        }
        // std::cout << "Planet_nr: " << active_objects[i]->get_object_id() << "   ForceX: " << active_objects[i]->get_current_force().x;
        // std::cout << " ForceY: " << active_objects[i]->get_current_force().y << " ForceY: " << active_objects[i]->get_current_force().y << std::endl;
    }
}

std::vector<std::tuple<Position, Time>> Gravity_System::get_trajectorie(unsigned int object_id) {
    for (const auto& object : active_objects) {
        if (object->get_object_id() == object_id) {
            return object->get_pos_history();
        }
    }
    return {}; // Return an empty vector if object_id is not found.
}

std::vector<unsigned int> Gravity_System::get_objects_id() {
    std::vector<unsigned int> object_ids;
    for (const auto& object : active_objects) {
        object_ids.push_back(object->get_object_id());
    }
    return object_ids;
}