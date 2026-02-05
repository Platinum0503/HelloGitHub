#include <iostream>
using namespace std;

enum Day {chuNhat = 1,thuHai = 2, thuBa = 3, thuTu = 4,
             thuNam = 5, thuSau = 6, thuBay = 7};

int main(){
    Day today = chuNhat;

    switch(today){
        case chuNhat:
            cout << "It is Chu Nhat";
            break;
        case thuHai:
            cout << "It is thu Hai";
            break;
        case thuBa:
            cout << "It is thu Ba";
            break;
        case thuTu:
            cout << "It is thu Tu";
            break;
        case thuNam:
            cout << "It is thu Nam";
            break;
        case thuSau:
            cout << "It is thu Sau";
            break;
        case thuBay:
            cout << "It is thu Bay";
            break;
    }
    return 0;
}