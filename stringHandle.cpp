#include <stdio.h>
#include <string.h>
#include <stdlib.h> //caution

void inputString(char *str){ //caution
    printf("Nhap chuoi cua ban: ");
    fgets(str, 100, stdin); //caution
    //strcspn delete \n
    str[strcspn(str, "\n")] = '\0'; //tìm kí tự \n sau đó thay thành \0
    printf(">>>Da nhap: '%s'\n", str); 
}

void searchString(char str[]){ //caution
    char timKiem[50]; //caution ko được trùng tên với con trỏ ở trên

    printf("Nhap tu ma ban muon tim kiem: ");
    fgets(timKiem, sizeof(timKiem), stdin);
    timKiem[strcspn(timKiem, "\n")] = '\0'; //loai bo xuong dong

    if(strstr(str, timKiem) != NULL){
        printf(">>> Tim thay '%s' trong chuoi!\n", timKiem);
    }else {
        printf(">>> khong tim thay '%s' trong chuoi.\n", timKiem);
    }
}

void demSolan(char str[]){  //caution
    char timKiem[50];
    int count = 0;

    printf("\n=== Dem so lan xuat hien ===\n");
    printf("Nhap chuoi can dem: ");
    fgets(timKiem, sizeof(timKiem), stdin);
    timKiem[strcspn(timKiem, "\n")] = '\0'; //caution

    char *pos = str; //caution
    int len = strlen(timKiem); //caution

    //tìm từng lần xuất hiện
    while((pos = strstr(pos, timKiem)) != NULL){
        count++;
        pos += len; //di chuyển qua chuỗi vừa tìm
    }

    printf(">>> '%s' xuất hiện %d lần trong chuỗi.\n", timKiem, count);
}

void email(char str[]){ //caution
    char email[100];

    printf("Nhap email cua ban: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    if(strstr(email, "@gmail.com") != NULL){
        printf("Tim Thay!\n");
    } else {
        printf("Khong tim thay @gmail.com");
    }
}

void menu(){
    printf("\n=== MENU ===\n");
    printf("1.Nhap chuoi\n");
    printf("2.Search chuoi\n");
    printf("3.Count xuat hien trong chuoi\n");
    printf("4.Check email true or false\n");
    printf("0.Thoat\n");
    printf("Nhap lua chon cua ban: ");
}

int main(){
    char str[100] = "";    //chuỗi chính //caution
    int daNhap = 0;  //cờ kiểm tra đã nhập
    int luaChon;

    do {
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');
        
        switch(luaChon){
            case 1:
                inputString(str);
                daNhap = 1;
                break;
            case 2:
                if(!daNhap){
                    printf(">>> Vui long nhap chuoi truoc!(chon 1)\n");
                } else {
                    searchString(str);
                }
                break;
            case 3:
                if(!daNhap){
                    printf(">>> Vui long nhap chuoi truoc!(chon 1)\n");  
                } else {
                    demSolan(str);
                }
                break;
            case 4: 
                email(str);
                break;
            case 0:
                printf(">>>Dang Thoat. Tam Biet!\n");
                break;
            default:
                printf("Nhap khong hop le! Nhap lai");
        }

    }while(luaChon != 0);

    return 0;
}