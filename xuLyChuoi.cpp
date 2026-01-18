#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void nhapChuoi(char str[]){
    char chuoi[50];
    printf("Nhap chuoi: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    printf("\nDa nhap thanh cong %s vao", chuoi);
}

void timKiem(char str[]){
    char timKiem[50];
    printf("Nhap chuoi ban muon tim: ");
    fgets(timKiem, sizeof(timKiem), stdin);
    timKiem[strcspn(timKiem, "\n")] = '\0'; //loại bỏ xuống dòng
    
    if(strstr(str ,timKiem) != NULL){
        printf("\nTim thay %s ", timKiem);
    } else {
        printf("\nKhong tim thay %s ", timKiem);
    }
}

void checkEmail(char str[]){
    char email[50];
    printf("Nhap email cua ban: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    if(strstr(email, "@gmail.com") != NULL){ //caution strstr
        printf("\nTim thay @gmail.com");
    } else {
        printf("\nKhong tim thay @gmail.coms");
    }
}

void demChuoi(char str[]){
    char chuoi[50];
    int count = 0;

    printf("\nNhap chuoi cua ban: ");
    fgets(chuoi, sizeof(chuoi), stdin);
    chuoi[strcspn(chuoi, "\n")] = '\0'; //loại bỏ xuống dòng

    char *pos = str;
    int len = strlen(chuoi);

    while(*pos = strstr(str, chuoi) != NULL){
        count++;
        pos += len;
    }
    printf(">>> %s xuat hien %d lan trong chuoi.", chuoi, count);
}

void menu(){
    printf("\n=== MENU ===\n");
    printf("1.Nhap chuoi\n");
    printf("2.Search chuoi\n");
    printf("3.Dem so lan xuat hien trong chuoi\n");
    printf("4.Check email co chua @gmail.com khong\n");
    printf("0.Thoat\n");
    printf("Nhap lua chon cua ban: ");
}

int main(){
    char str[100] = "";
    int daNhap = 0;
    int luaChon;

    do {
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');

        switch(luaChon){
            case 1: 
                nhapChuoi(str);
                daNhap = 1;
                break;
            case 2: 
                if(!daNhap){
                    printf(">>> Vui long nhap chuoi truoc!(chon 1)\n");
                } else {
                timKiem(str);
                }
                break;
            case 3: 
             if(!daNhap){
                    printf(">>> Vui long nhap chuoi truoc!(chon 1)\n");  
                } else {
                demChuoi(str);
                }
                break;
            case 4: 
                checkEmail(str);
                break;
            case 0: 
                printf("\n>>>Dang thoat. Tam Biet!");
                break;
            default: 
                printf("\nLua chon khong hop le! Nhap lai: ");
                break;
        }

    }while(luaChon != 0); 

    return 0;
}