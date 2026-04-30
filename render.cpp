#include "traffic.h"

void DrawVehicle(const Vehicle& v){
    DrawRectangleRec(v.rect,v.color);
}

void DrawScene(std::vector<Vehicle>& vehicles){
    BeginDrawing();
    ClearBackground(DARKGREEN);

    for(auto &v:vehicles) DrawVehicle(v);

    EndDrawing();
}
