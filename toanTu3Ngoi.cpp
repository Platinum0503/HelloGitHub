#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void timMax(){
    float a,b;
    printf("Nhap gia tri a: ");
    scanf("%f", &a);
    while(getchar() != '\n');
    printf("Nhap gia tri b: ");
    scanf("%f", &b);

    float max = (a > b) ? a : b;
    printf("Gia tri lon nhat la: %f ", max);
}

void check(){
    int a;
    printf("Nhap so nguyen cua ban: ");
    scanf("%d", &a);
    while(getchar() != '\n');

    const char* check = (a % 2 == 0) ? "Chan" : "Le";
    printf("so nguyen %d la %s", a, check);
}

float my_abs(float x){
    return (x < 0) ? -x : x;
}

void id(){
    static int lastID = 0; //lưu id cuối cùng

    printf("\n=== TAO ID TU DONG ===\n");

    lastID++;
    printf(">>> ID moi (tang dan): %d\n", lastID);

    int randomID = rand() % 9000 + 1000;
    printf(">>> ID moi: (ngau nhien) %d\n", randomID);
}

void tuyetDoi(){
    float a;
    printf("Nhap so nguyen cua ban: ");
    scanf("%f", &a);
    while(getchar() != '\n');

    float result = my_abs(a);
    printf("so tuyet doi cua %.2f la %.2f ", a, result);
}

void menu(){
    printf("\n=== MENU ===\n");
    printf("1.Tim so lon nhat\n");
    printf("2.Kiem tra Chan/Le\n");
    printf("3.Gia tri tuyet doi\n");
    printf("4.Tao ID tu dong\n");
    printf("0.Thoat\n");
    printf("Nhap lua chon cua ban: ");
}

int main(){
    srand(time(NULL));
    int luaChon;

    do {
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');

        switch(luaChon){
            case 1: 
                timMax();
                break;
            case 2: 
                check();
                break;
            case 3:
                tuyetDoi();
                break;
            case 4: 
                id();
                break;
            case 0:
                printf("\nDang Thoat. Tam Biet!");
                break;
            default: 
                printf("\nNhap khong hop le! Nhap lai: ");
        }

    }while(luaChon != 0);

    return 0;
}