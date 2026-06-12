#include "helpers.h"
#include "constants.h"
#include <cmath>

int CountLane(const std::vector<Vehicle>& v, int dir) {
    int c = 0;
    for (const auto& x : v) if (x.direction == dir) c++;
    return c;
}

bool AmbulanceInLane(const std::vector<Vehicle>& v, int dir) {
    for (const auto& x : v)
        if (x.direction == dir && x.isAmbulance) return true;
    return false;
}

int CountApproaching(const std::vector<Vehicle>& vehicles, int dir) {
    int c = 0;
    for (const auto& v : vehicles) {
        if (v.direction != dir) continue;
        switch (dir) {
            case 0: if (v.rect.y + v.rect.height < ROAD_BOT) c++; break;
            case 1: if (v.rect.y > ROAD_TOP)                 c++; break;
            case 2: if (v.rect.x + v.rect.width < ROAD_RIGHT)c++; break;
            case 3: if (v.rect.x > ROAD_LEFT)                c++; break;
        }
    }
    return c;
}

void DrawDashedLine(int x1, int y1, int x2, int y2, int dashLen, Color c) {
    float dx = (float)(x2 - x1), dy = (float)(y2 - y1);
    float len = sqrtf(dx*dx + dy*dy);
    int   steps = (int)(len / (dashLen * 2));
    float nx = dx/len, ny = dy/len;
    for (int i = 0; i < steps; i++) {
        float sx = x1 + nx * i * dashLen * 2;
        float sy = y1 + ny * i * dashLen * 2;
        DrawLineEx({sx, sy}, {sx + nx*dashLen, sy + ny*dashLen}, 3, c);
    }
}
