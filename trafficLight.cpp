#include <iostream>
#include <string>
using namespace std;

enum trafficLight {RED, YELLOW, GREEN};

string canGO(trafficLight Can){
    switch(Can){
        case trafficLight::RED: return "STOP";
        case trafficLight::YELLOW: return "MOVE SLOW AND STOP";
        case trafficLight::GREEN: return "Can Go";
        default: return "Khong xac dinh";
    }
}
trafficLight nextLight(trafficLight currnet){
        switch(currnet){
            case RED: return YELLOW;
            case YELLOW: return GREEN;
            case GREEN: return RED;
            default: return RED;
    }
}
int main(){
    trafficLight light = trafficLight::RED;

    cout << "Bay gio: " << canGO(light) << endl;
    
    light = nextLight(light);
    cout << "Next: " << canGO(light) << endl;

    light = nextLight(light);
    cout << "Next: " << canGO(light) << endl;
    return 0;
}