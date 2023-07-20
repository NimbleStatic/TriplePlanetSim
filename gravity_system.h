#ifndef GRAVITY_SYSTEM_H
#define GRAVITY_SYSTEM_H
#include "force_object.h"
#include <cmath>
#include "structs.h"
#include"vector"
#include"tuple"
#include "memory"

class Gravity_System{
    private:
        std::vector<std::unique_ptr<Force_Object>> active_objects;
        Time time_step;
        Time full_time;
        long double g_const;
    public:
        Gravity_System(Time time_step);
        bool add_object(std::unique_ptr<Force_Object> new_object);
        bool delete_object_by_id(unsigned id);
        void update_system(Time step);
        void simulate_system(Time time_to_sim);
        void update_system();
        void update_gravity_forces();
        std::vector<std::tuple<Position,Time>> get_trajectorie(unsigned int object_id);
        std::vector<unsigned int> get_objects_id();
};



#endif