#include <iostream>
#include <string>
#include <vector> //caution
 //   #include <chrono> //là thư viện để làm việc với thời gian
using namespace std;

enum class Character{IDLE, WALKING, RUNNING, JUMPING, ATTACKING, DEAD};

string stateNow(Character now){
    switch(now){
        case Character::IDLE:       return "IDLE";
        case Character::WALKING:    return "WALKING";
        case Character::RUNNING:    return "RUNNING";
        case Character::JUMPING:    return "JUMPING";
        case Character::ATTACKING:  return "ATTACKING";
        case Character::DEAD:       return "DEAD";
        default: return "Loi";
    }
}
bool canTransition(Character current, Character newState){
    //k thể chuyển từ dead --> state khác
    if(current == Character::DEAD){
        return false;   
    }

    //cant attacking during jumping
    if(current == Character::JUMPING && newState == Character::ATTACKING){
        return false;
    }
    //cant jump during attacking
    if(current == Character::ATTACKING && newState == Character::JUMPING){
        return false;
    }
    return true;
}
Character transition(Character current, Character newState){ //caution
    if(canTransition(current, newState)){
        return newState;
    }else {
        cout << "Cannot transition from " << stateNow(current)
        << " to " << stateNow(newState) << endl;
        return current; //giữ nguyên state cũ
    }
}
int main(){
    Character current = Character::IDLE;
    vector<Character> history; //luu lich su

    //luu state first
    history.push_back(current);

    cout << "=== INIIAL STATE ===" << endl;
    cout << "current: " << stateNow(current) << endl;
    
    //test trasition hop le
    cout << "\n=== VALID TRANSITION ===" << endl;
    current = transition(current, Character::WALKING);
    history.push_back(current);
    cout << "Now: " << stateNow(current) << endl;

    current = transition(current, Character::RUNNING);
    history.push_back(current);
    cout << "Now: " << stateNow(current) << endl;

    current = transition(current, Character::ATTACKING);
    history.push_back(current);
    cout << "Now: " << stateNow(current) << endl;

    //về IDLE rồi thử attack
    current = transition(current, Character::IDLE);
    history.push_back(current);
    cout << "Now: " << stateNow(current) << endl;

    current = transition(current, Character::ATTACKING);
    history.push_back(current);
    cout << "Now: " <<  stateNow(current) << endl;

    //test cant jump during attacking
    Character temp = transition(current, Character::JUMPING);
    cout << "Current: " << stateNow(current) << endl;

    //test dead state
    cout << "\n=== DEATH ===" << endl;
    current = transition(current, Character::DEAD);
    history.push_back(current);
    cout << "Now: " << stateNow(current) << endl;

    //cant chuyển từ dead
    temp = transition(current, Character::IDLE);
    cout << "Current: " << stateNow(current) << endl;

    //in lich su
    cout << "\n=== STATE HISTORY ===" << endl;
    for(int i = 0; i < history.size();i++){
        cout << i+1 <<". " << stateNow(history[i]) << endl;
    }

    return 0;
}