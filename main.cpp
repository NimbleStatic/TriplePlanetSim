#include <iostream>
#include "force_object.h"
#include "structs.h"
#include"vector"
#include"tuple"

int main() {
    Position initialPosition {0, 0, 0};
    Force_Object obj(10.0, 1.0, initialPosition);

    obj.set_force(5.0, 0.0, 0.0);
    obj.set_velocity(0.0, 2.0, 0.0);

    Time timeStep {1.0};
    for (int i = 0; i < 5; ++i) {
        obj.move_in_time(timeStep);
        Position currentPosition = obj.get_current_pos();
        Velocity currentVelocity = obj.get_current_velocity();
        std::cout << "Position (x, y, z): (" << currentPosition.x << ", " << currentPosition.y << ", " << currentPosition.z << ")" << std::endl;
        std::cout << "Velocity (x, y, z): (" << currentVelocity.x << ", " << currentVelocity.y << ", " << currentVelocity.z << ")" << std::endl;
    }

    std::vector<std::tuple<Position, Time>> history = obj.get_pos_history();
    std::cout << "Position history:" << std::endl;
    for (const auto& entry : history) {
        Position pos = std::get<0>(entry);
        Time time = std::get<1>(entry);
        std::cout << "Position (x, y, z) at t = " << time.time << ": (" << pos.x << ", " << pos.y << ", " << pos.z << ")" << std::endl;
    }

    return 0;
}