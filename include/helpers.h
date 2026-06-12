#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include "vehicle.h"
#include "raylib.h"

int CountLane(const std::vector<Vehicle>& v, int dir);
bool AmbulanceInLane(const std::vector<Vehicle>& v, int dir);
int CountApproaching(const std::vector<Vehicle>& vehicles, int dir);
void DrawDashedLine(int x1, int y1, int x2, int y2, int dashLen, Color c);

#endif // HELPERS_H
