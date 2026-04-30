#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <vector>
#include "raylib.h"

enum IntersectionState { NS_GREEN, NS_YELLOW, EW_GREEN, EW_YELLOW };

struct Vehicle {
    Rectangle rect;
    Color color;
    int direction;
    float speed;
    float maxSpeed;
    bool isAmbulance;
};

int CountLane(const std::vector<Vehicle>& v, int dir);
bool AmbulanceInLane(const std::vector<Vehicle>& v, int dir);
int CountApproaching(const std::vector<Vehicle>& vehicles, int dir);

void UpdateTraffic(IntersectionState& state, float& timer,
                   const std::vector<Vehicle>& vehicles, float dt);

#endif
