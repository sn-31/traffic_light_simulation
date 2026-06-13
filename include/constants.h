#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "raylib.h"


//  GEOMETRY CONSTANTS
static const int   W          = 1200;
static const int   H          = 900;
static const int   ROAD_W     = 220;   
static const int   LANE_W     = ROAD_W / 2;

// Road centre lines
static const int   RCX        = W / 2;
static const int   RCY        = H / 2; 

// Road edges
static const int   ROAD_LEFT  = RCX - ROAD_W / 2;
static const int   ROAD_RIGHT = RCX + ROAD_W / 2;
static const int   ROAD_TOP   = RCY - ROAD_W / 2;
static const int   ROAD_BOT   = RCY + ROAD_W / 2;

// Stop lines 
static const int   STOP_S     = ROAD_TOP  - 5;   
static const int   STOP_N     = ROAD_BOT  + 5;  
static const int   STOP_E     = ROAD_LEFT - 5;   
static const int   STOP_W     = ROAD_RIGHT+ 5;  

// Traffic light timing
static const float MIN_GREEN  =  4.0f;
static const float MAX_GREEN  = 22.0f;
static const float BASE_GREEN = 10.0f;
static const float YELLOW_DUR =  2.0f;

#endif // CONSTANTS_H
