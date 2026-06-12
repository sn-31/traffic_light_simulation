#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <vector>
#include "vehicle.h"

enum IntersectionState { NS_GREEN, NS_YELLOW, EW_GREEN, EW_YELLOW };

void UpdateTraffic(IntersectionState& state, float& timer,
                   const std::vector<Vehicle>& vehicles, float dt);

#endif // TRAFFIC_H
