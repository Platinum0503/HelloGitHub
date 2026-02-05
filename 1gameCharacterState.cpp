#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Character {
    IDLE,
    WALKING,
    RUNNING,
    JUMPING,
    ATTACKING,
    DEAD
};
string stateNow(Character now){
    switch(now){
        case Character::IDLE:       return "IDLE";
        case Character::WALKING:    return "WALKING";
        case Character::RUNNING:    return "RUNNNING";
        case Character::JUMPING:    return "JUMPING";
        case Character::ATTACKING:  return "ATTACKING";
        case Character::DEAD:       return "DEAD";
        default: return "UNKNOWN";
    }
}
bool canTransition(Character current, Character newState){
    if(current == Character::DEAD){
        return false;
    }
    if(current == Character::JUMPING && newState == Character::ATTACKING){
        return false;
    }
    if(current == Character::ATTACKING && newState == Character::JUMPING){
        return false;
    }
    return true;
}
Character transition(Character current, Character newState){
    if(canTransition(current, newState)){
        return newState;
    } else{
        cout << "Cannot transition from " << stateNow(current) << 
                " to " << stateNow(newState) << endl;
        return current;
    }
}
int main(){
    Character current = Character::IDLE;
    vector<Character> history;

    history.push_back(current);

    cout << "\n=== INITAL STATE ===" << endl;
    cout << "Current: " << stateNow(current) << endl;

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

    Character temp = transition(current, Character::JUMPING);
    cout << "current: " << stateNow(current) << endl;

    cout << "\n=== DEAD ===" << endl;
    current = transition(current, Character::DEAD);
    history.push_back(current);
    cout << "Now: " << stateNow(current) << endl;

    temp = transition(current, Character::IDLE);
    cout << "Now: " << stateNow(current) << endl;

    cout << "\n=== STATE HISTORY ===" << endl;
    for(int i = 0; i < history.size();i++){
        cout << i+1 << ". " << stateNow(history[i]) << endl;
    }
    return 0;
}