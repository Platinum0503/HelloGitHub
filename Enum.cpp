#include <iostream>
using namespace std;
 /*
    Enums (Các phép liệt kê)
    Kiểu dữ liệu do người dùng định nghĩa, bao gồm các hằng số nguyên có tên.
    Ví dụ: các ngày trong tuần, các hành tinh, các hương vị.
    Enum giúp cải thiện khả năng đọc hiểu và tính an toàn so với các số nguyên hoặc chuỗi ký tự thông thường.
    Biến kiểu liệt kê chỉ có thể chứa một trong các giá trị được đặt tên đã định nghĩa
*/
//we cant not use string/char in switch

enum Day {sunday = 0, monday = 1, tuesday = 2, wenesday = 3,
         thursday = 4, friday = 5, saturday = 6};
int main(){
    Day today = sunday;

    switch(today){
        case 0:
            cout << "It is Sunday!\n";
            break;
        case 1:
            cout << "It is Monday!\n";
            break;
        case 2:
            cout << "It is Tuesday!\n";
            break;
        case 3:
            cout << "It is Wenesday!\n";
            break;
        case 4:
            cout << "It is Thursday!\n";
            break;
        case 5:
            cout << "It is Friday!\n";
            break;
        case 6:
            cout << "It is Saturday!\n";
            break;
    }

    return 0;
}