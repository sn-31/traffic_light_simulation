#include "raylib.h"
#include "constants.h"
#include "vehicle.h"
#include "traffic.h"
#include "render.h"
#include "input.h"
#include "helpers.h"
#include <vector>

int main() {
    InitWindow(W, H, "Smart Traffic Simulation - Modular");
    SetTargetFPS(60);

    std::vector<Vehicle> vehicles;
    IntersectionState state = NS_GREEN;
    float timer   = 0;
    float nsGreen = BASE_GREEN;
    float ewGreen = BASE_GREEN;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        HandleInput(vehicles);

        // recalculate green times for HUD display
        {
            int ns = CountLane(vehicles,0)+CountLane(vehicles,1);
            int ew = CountLane(vehicles,2)+CountLane(vehicles,3);
            int total = ns+ew;
            if (total > 0) {
                nsGreen = MIN_GREEN + ((float)ns/total)*(MAX_GREEN-MIN_GREEN);
                ewGreen = MIN_GREEN + ((float)ew/total)*(MAX_GREEN-MIN_GREEN);
            } else {
                nsGreen = ewGreen = BASE_GREEN;
            }
        }

        UpdateTraffic(state, timer, vehicles, dt);
        UpdateVehicles(vehicles, state, dt);

        DrawScene(W, H, vehicles, state, timer, nsGreen, ewGreen);
    }

    CloseWindow();
    return 0;
}
