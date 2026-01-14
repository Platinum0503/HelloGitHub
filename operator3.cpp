#include <stdio.h>
#include <math.h>
#include <time.h> //chứa time()
#include <stdlib.h> //chứa rand() và srand()
float my_abs(float x){
    return (x < 0) ? -x : x;
}

void menu(){
    printf("\n=== MENU ===\n");
    printf("1.Tim so lon nhat\n");
    printf("2.Kiem tra Chan/Le\n");
    printf("3.Gia tri tuyet doi\n");
    printf("4.Tao ID tu dong\n");
    printf("0.Thoat\n");
}

void timSoLonNhat(){
    int a;
    int b;
    printf("Nhap gia tri a: ");
    scanf("%d", &a);
    while(getchar() != '\n');
    printf("Nhap gia tri b: ");
    scanf("%d", &b);

    printf("gia tri lon nhat la: ");
    int max = (a > b) ? a : b;
    printf("%d", max);
}

void checkChanLe(){ //bỏ tham số
    int so;
    printf("Nhap gia tri c (kiem tra chan/le): ");
    scanf("%d", &so);

    const char* ketQua = (so % 2 == 0) ? "chan" : "le"; 
    printf(">>> %d la so %s\n", so, ketQua);
}

void checkTuyetDoi(){ //bỏ tham số
    float so;
    printf("Nhap gia tri cua ban: ");
    scanf("%f", &so);

    float result = my_abs(so);
    printf("Gia tri tuyet doi: %.2f la %.2f\n",so, result);
}

void idTuDong(){ //bỏ tham số
    static int lastID = 0; //lưu id cuối cùng

    printf("\n=== TAO ID TU DONG ===\n");

    //cách 1: ID tăng dần từ 1
    lastID++;
    printf(">>> ID moi (tang dan): %d\n", lastID);

    //cach 2: ID random
    int randomID = rand() % 9000 + 1000; //1000-9999
    printf(">>> ID moi (ngau nhien: %d\n)", randomID);
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
                timSoLonNhat();
                break;
            case 2:
                checkChanLe();
                break;
            case 3:
                checkTuyetDoi();
                break;
            case 4: 
                idTuDong();
                break;
            case 0:
                printf("\n>>> Dang thoat. Tam biet!\n");
                break;
            default:
                printf("\nNhap khong hop le! Vui long nhap lai: ");
        }
    }while(luaChon != 0);

    
    return 0;
}