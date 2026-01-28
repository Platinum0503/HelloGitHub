#include <iostream>
#include <string>
using namespace std;

enum class Permission {NONE = 0, // 000 ko có quyền gì
                     READ = 4, //100 chỉ đọc
                     WRITE = 2, //010 chỉ ghi
                     EXECUTE = 1}; //001 chỉ thực thi
//kiểm tra quyền
bool hasPermission(int userPerms, Permission p){ 
    int permValue = static_cast<int>(p);
    return (userPerms & permValue) != 0;
}
void addPermission(int& userPerms, Permission p){
    int permValue = static_cast<int>(p);
    userPerms = userPerms | permValue;
}
void removePermission(int& userPerms, Permission p){
    // dùng & và ~ (AND và NOT)
    int permValue = static_cast<int>(p);
    userPerms = userPerms & (~permValue);
    //or ngắn gọn hơn
    // userPerms &= ~permValue;
}
void printPermission(int perms){
    cout << "Permissions (" << perms << "): ";

    if(hasPermission(perms, Permission::READ)){
        cout << "READ";
    }
    if(hasPermission(perms, Permission::WRITE)){
        cout << "WRITE";
    }
    if(hasPermission(perms, Permission::EXECUTE)){
        cout << "EXECUTE";
    }
    if(perms == 0){
        cout << "NONE";
    }
    cout << endl;
}
int main(){
    int userPerms = 0; //bắt đầu không có quyền gì

    cout << "=== INITIAL STATE ===" << endl;
    printPermission(userPerms);

    //them quyen READ
    cout << "\n=== ADD READ ===\n";
    addPermission(userPerms, Permission::READ);
    printPermission(userPerms);
    

    cout << "\n=== ADD WRITE ===\n";
    addPermission(userPerms, Permission::WRITE);
    printPermission(userPerms);

    cout << "\n=== ADD EXECUTE ===\n";
    addPermission(userPerms, Permission::EXECUTE);
    printPermission(userPerms);

    cout << "\n=== REMOVE WRITE ===\n";
    removePermission(userPerms, Permission::WRITE);
    printPermission(userPerms);

    cout << "\n=== CHECK PERMISSIONS ===" << endl;
    cout << "Can READ? " << (hasPermission(userPerms, Permission::READ) ? "YES" : "NO") << endl;
    cout << "Can WRITE? " << (hasPermission(userPerms, Permission::WRITE) ? "YES" : "NO") << endl;
    cout << "Can EXECUTE? " << (hasPermission(userPerms, Permission::EXECUTE) ? "YES" : "NO") << endl;
    
    return 0;
}