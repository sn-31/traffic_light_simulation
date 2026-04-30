#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include "traffic.h"

void SpawnVehicle(std::vector<Vehicle>& vehicles,int dir,bool amb);
void UpdateVehicles(std::vector<Vehicle>& vehicles,
                    IntersectionState state,float dt);

#endif
