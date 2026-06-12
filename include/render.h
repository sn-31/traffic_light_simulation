#ifndef RENDER_H
#define RENDER_H

#include <vector>
#include "vehicle.h"
#include "traffic.h"

void DrawTrafficLight(int x, int y, Color active);
void DrawVehicle(const Vehicle& v);
void DrawUI(int screenW);
void DrawHUD(const std::vector<Vehicle>& vehicles,
             IntersectionState state, float timer,
             float nsGreen, float ewGreen);
void DrawScene(int screenW, int screenH, const std::vector<Vehicle>& vehicles,
               IntersectionState state, float timer,
               float nsGreen, float ewGreen);

#endif // RENDER_H
