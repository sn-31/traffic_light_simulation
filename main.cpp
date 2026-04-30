#include "raylib.h"
#include <vector>
#include "traffic.h"
#include "vehicle.h"

void DrawScene(std::vector<Vehicle>&);

int main(){
    InitWindow(1200,900,"Traffic");
    SetTargetFPS(60);

    std::vector<Vehicle> vehicles;
    IntersectionState state=NS_GREEN;
    float timer=0;

    while(!WindowShouldClose()){
        float dt=GetFrameTime();

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            SpawnVehicle(vehicles,GetRandomValue(0,3),false);

        UpdateTraffic(state,timer,vehicles,dt);
        UpdateVehicles(vehicles,state,dt);

        DrawScene(vehicles);
    }

    CloseWindow();
}
