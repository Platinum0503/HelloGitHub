#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Language {ENGLISH, VIETNAMESE, JAPANESE};

enum class MenuItem {
    NEW_GAME, LOAD_GAME, SETTING, EXIT
};
string getMenuText(MenuItem item, Language lang){ //use if/else or switch lồng nhai
    if(item == MenuItem::NEW_GAME){
        switch(lang){
            case Language::ENGLISH:     return "NEW_GAME";
            case Language::VIETNAMESE:  return "Tro choi moi";
            case Language::JAPANESE:    return "新しいゲーム";
            default:                    return "NEW_GAME";
        }
    }
    else if(item == MenuItem::LOAD_GAME){
        switch(lang){
            case Language::ENGLISH:     return "Load Game";
            case Language::VIETNAMESE:  return "Tai Game";
            case Language::JAPANESE:    return "ゲームをロード";
            default:                    return "Load Game";
        }
    }
    else if(item == MenuItem::SETTING){
        switch(lang) {
            case Language::ENGLISH:    return "Settings";
            case Language::VIETNAMESE: return "Cai Dat";
            case Language::JAPANESE:   return "設定";
            default:                   return "Settings";
        }
    }
    else if(item == MenuItem::EXIT){
         switch(lang) {
            case Language::ENGLISH:    return "Exit";
            case Language::VIETNAMESE: return "Thoat";
            case Language::JAPANESE:   return "終了";
            default:                   return "Exit";
        }
    }
    return "UNKNOWN";
}
string getLanguageName(Language lang) {
    switch(lang) {
        case Language::ENGLISH:    return "English";
        case Language::VIETNAMESE: return "Tieng Viet";
        case Language::JAPANESE:   return "日本語";
        default:                   return "Unknown";
    }
}
void displayMenu(Language lang){ //dùng lang !!!caution
    cout << "\n=== MENU ===\n";
    cout << "1. " << getMenuText(MenuItem::NEW_GAME, lang) << endl;
    cout << "2. " << getMenuText(MenuItem::LOAD_GAME, lang) << endl;
    cout << "3. " << getMenuText(MenuItem::SETTING, lang) << endl;
    cout << "4. " << getMenuText(MenuItem::EXIT, lang) << endl;
    cout << "5. ";
    switch(lang){
        case Language::ENGLISH:     cout << "Change Language"; break;
        case Language::VIETNAMESE:  cout << "Doi Ngon Ngu"; break;
        case Language::JAPANESE:    cout << "言語を変更"; break;
    }
    cout << endl;

    cout << "6. ";
    switch(lang){
        case Language::VIETNAMESE: cout << "Lich Su"; break;
        case Language::ENGLISH:    cout << "History"; break;
        case Language::JAPANESE:   cout << "歴史"; break;
    }
    cout << endl;
    cout << "Nhap lua chon / Enter choice: ";
}
Language selectLanguage() {
    cout << "\n--- SELECT LANGUAGE ---" << endl;
    cout << "1. English" << endl;
    cout << "2. Tieng Viet" << endl;
    cout << "3. 日本語 (Japanese)" << endl;
    cout << "Nhap lua chon: ";
    
    int choice;
    cin >> choice;
    
    switch(choice) {
        case 1: return Language::ENGLISH;
        case 2: return Language::VIETNAMESE;
        case 3: return Language::JAPANESE;
        default: 
            cout << "Lua chon khong hop le! Mac dinh: English" << endl;
            return Language::ENGLISH;
    }
}
void printHistory(const vector<Language>& history) {
    if(history.empty()) {
        cout << "Chua co lich su thay doi ngon ngu." << endl;
        return;
    }
    
    cout << "\n=== LICH SU NGON NGU ===" << endl;
    for(int i = 0; i < history.size(); i++) {
        cout << i + 1 << ". " << getLanguageName(history[i]) << endl;
    }
}
int main(){
    Language lang = Language::ENGLISH;
    MenuItem item = MenuItem::NEW_GAME;
    vector<Language> history;

    int luaChon;
    do {
        displayMenu(lang);
        cin >> luaChon;
        while(getchar() != '\n');
        switch(luaChon){
            case 1: 
                cout << getMenuText(MenuItem::NEW_GAME, lang);
                break;
            case 2:
                cout << getMenuText(MenuItem::LOAD_GAME, lang);
                break;
            case 3:
                item = MenuItem::SETTING;
                cout << getMenuText(MenuItem::SETTING, lang);
                break;
            case 4:
                item = MenuItem::EXIT;
                cout << getMenuText(MenuItem::EXIT, lang);
                break;
            case 5:{
                Language newLang = selectLanguage();
                if(newLang != lang){
                    lang = newLang;
                    history.push_back(lang);
                    cout << "Ngon ngu da thay doi thanh: "
                         << getLanguageName(lang) << endl;
                }else {
                    cout << "\n!!!Ngon ngu khong thay doi." << endl;
                }
                break;
            }
            case 6:
                printHistory(history);
                break;

            default:
             cout <<"Nhap khong hop le!";
        }
    }while(luaChon != 4);
    return 0;
}