#include "input.h"
#include "constants.h"
#include "raylib.h"

void HandleInput(std::vector<Vehicle>& vehicles) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 m = GetMousePosition();
        int px = W - 200, py = 20;

        if (CheckCollisionPointRec(m,{(float)px+70,(float)py+42,18,18})) selectedType=0;
        if (CheckCollisionPointRec(m,{(float)px+70,(float)py+66,18,18})) selectedType=1;

        if (m.x < px) {
            bool onVertRoad = (m.x >= ROAD_LEFT && m.x <= ROAD_RIGHT);
            bool onHorzRoad = (m.y >= ROAD_TOP  && m.y <= ROAD_BOT);
            bool inBox      = onVertRoad && onHorzRoad;

            if (!inBox) {
                int dir = -1;
                if (onVertRoad && !onHorzRoad) {
                    dir = (m.x < RCX) ? 0 : 1;
                } else if (onHorzRoad && !onVertRoad) {
                    dir = (m.y > RCY) ? 2 : 3;
                }
                if (dir >= 0)
                    SpawnVehicle(vehicles, dir, selectedType==1);
            }
        }
    }
}
