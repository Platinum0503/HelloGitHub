#include <iostream>
using namespace std;

enum class Month{January = 1, Febnuary = 2, March = 3, April = 4, May = 5, June = 6, July = 7
            , August = 8, September = 9, October = 10, November = 11, December = 12};

int getDaysInMonth(Month n, bool isLeapYear = false){
    switch(n){
        case Month::January:     return 31;
        case Month::Febnuary:    return isLeapYear ? 29 : 28; //năm nhuận
        case Month::March:      return 31;
        case Month::April:      return 30;
        case Month::May:        return 31;
        case Month::June:       return 30;
        case Month::July:       return 31;
        case Month::August:     return 31;
        case Month::September:  return 30;
        case Month::October:    return 31;
        case Month::November:   return 30;
        case Month::December:   return 31;
        default: return 0;
    }
}
string getMonthName(Month n){
    switch(n){
        case Month::January:     return "January";
        case Month::Febnuary:    return "Febnuary";
        case Month::March:      return "March";
        case Month::April:      return "April";
        case Month::May:        return "May";
        case Month::June:       return "June";
        case Month::July:       return "July";
        case Month::August:     return "August";
        case Month::September:  return "September";
        case Month::October:    return "October";
        case Month::November:   return "November";
        case Month::December:   return "December";
        default:                return "Unknown";
    }
}
string getSeason(Month n){
    int monthNum = static_cast<int>(n); //convert enum sang int

    if(monthNum >= 1 && monthNum <= 3){
        return "Mua Xuan";
    } else if(monthNum >= 4 && monthNum <= 6){
        return "Mua ha";
    } else if(monthNum >= 7 && monthNum <= 9){
        return "Mua thu";
    } else if(monthNum >= 8 && monthNum <= 12){
        return "Mua Dong";
    } else {
        return "Khong xac dinh";
    }
}

int main(){
    Month now = Month::January;
    cout << "Thang " << getMonthName(now) << endl;
    cout << "co " << getDaysInMonth(now, false) << " ngay" << endl;
    cout << "co " << getDaysInMonth(now, true) << " ngay(Nam nhuan)" << endl;
    cout << "Mua: "<< getSeason(now);
    return 0;
}