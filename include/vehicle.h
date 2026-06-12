#ifndef VEHICLE_H
#define VEHICLE_H

#include "raylib.h"
#include <vector>

struct Vehicle {
    Rectangle rect;
    Color     color;
    int       direction;   // 0=S 1=N 2=E 3=W
    float     speed;       // current speed (px/s)
    float     maxSpeed;
    bool      isAmbulance;
};

// Global for UI (could be moved to input/render, but keeping for now)
extern int selectedType; 

void SpawnVehicle(std::vector<Vehicle>& vehicles, int dir, bool amb);
void UpdateVehicles(std::vector<Vehicle>& vehicles, int state, float dt);

#endif // VEHICLE_H
