#include "traffic.h"

static const float MIN_GREEN=4.0f, MAX_GREEN=22.0f, BASE_GREEN=10.0f, YELLOW_DUR=2.0f;

int CountLane(const std::vector<Vehicle>& v, int dir){
    int c=0; for(auto &x:v) if(x.direction==dir) c++; return c;
}

bool AmbulanceInLane(const std::vector<Vehicle>& v,int dir){
    for(auto &x:v) if(x.direction==dir && x.isAmbulance) return true;
    return false;
}

int CountApproaching(const std::vector<Vehicle>& vehicles,int dir){
    int c=0;
    for(auto &v:vehicles){
        if(v.direction!=dir) continue;
        switch(dir){
            case 0: if(v.rect.y+v.rect.height<900/2+110)c++;break;
            case 1: if(v.rect.y>900/2-110)c++;break;
            case 2: if(v.rect.x+v.rect.width<1200/2+110)c++;break;
            case 3: if(v.rect.x>1200/2-110)c++;break;
        }
    }
    return c;
}

void UpdateTraffic(IntersectionState& state,float& timer,
                   const std::vector<Vehicle>& vehicles,float dt){
    timer+=dt;

    int ns=CountLane(vehicles,0)+CountLane(vehicles,1);
    int ew=CountLane(vehicles,2)+CountLane(vehicles,3);

    bool nsAmb=AmbulanceInLane(vehicles,0)||AmbulanceInLane(vehicles,1);
    bool ewAmb=AmbulanceInLane(vehicles,2)||AmbulanceInLane(vehicles,3);

    if(nsAmb&&!ewAmb){state=NS_GREEN;timer=0;return;}
    if(ewAmb&&!nsAmb){state=EW_GREEN;timer=0;return;}

    int total=ns+ew;
    float nsGreen=BASE_GREEN, ewGreen=BASE_GREEN;
    if(total>0){
        nsGreen=MIN_GREEN+((float)ns/total)*(MAX_GREEN-MIN_GREEN);
        ewGreen=MIN_GREEN+((float)ew/total)*(MAX_GREEN-MIN_GREEN);
    }

    switch(state){
        case NS_GREEN: if(timer>nsGreen){state=NS_YELLOW;timer=0;} break;
        case NS_YELLOW: if(timer>YELLOW_DUR){state=EW_GREEN;timer=0;} break;
        case EW_GREEN: if(timer>ewGreen){state=EW_YELLOW;timer=0;} break;
        case EW_YELLOW: if(timer>YELLOW_DUR){state=NS_GREEN;timer=0;} break;
    }
}
