#include "vehicle.h"

void SpawnVehicle(std::vector<Vehicle>& vehicles,int dir,bool amb){
    Vehicle v;
    v.direction=dir;
    v.isAmbulance=amb;
    v.maxSpeed=amb?300.0f:180.0f;
    v.speed=v.maxSpeed;
    v.color=amb?RAYWHITE:BLUE;

    if(dir==0) v.rect={590,-60,30,50};
    if(dir==1) v.rect={610,920,30,50};
    if(dir==2) v.rect={-60,460,50,30};
    if(dir==3) v.rect={1220,440,50,30};

    vehicles.push_back(v);
}

void UpdateVehicles(std::vector<Vehicle>& vehicles,
                    IntersectionState state,float dt){

    for(auto &v:vehicles){
        if(v.direction==0) v.rect.y+=v.speed*dt;
        if(v.direction==1) v.rect.y-=v.speed*dt;
        if(v.direction==2) v.rect.x+=v.speed*dt;
        if(v.direction==3) v.rect.x-=v.speed*dt;
    }

    for(auto it=vehicles.begin();it!=vehicles.end();){
        if(it->rect.x<-200||it->rect.x>1400||
           it->rect.y<-200||it->rect.y>1100)
            it=vehicles.erase(it);
        else ++it;
    }
}
