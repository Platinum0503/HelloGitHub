#include <stdio.h>

struct array {
    float a,b;
};

void nhapNumber(float *a, float *b){
    printf("\n=== Nhap Number ===\n");
    printf("Nhap a: ");
    scanf("%f", a); //caution

    printf("\nNhap b: ");
    scanf("%f", b); //caution

    while(getchar() != '\n');
}

void swap(float *a, float *b){
    printf("\n=== Swap a & b ===\n");
    printf("Gia tri hien tai a la: %.2f\n", *a);  //caution
    printf("Gia tri hien tai b la: %.2f\n", *b);  //caution

    float temp = *a;
    *a = *b;
    *b = temp;
    printf("=== Swap ===\n");
    printf(">>> Swap thanh cong!\n");

    
}

void printNumber(float a, float b){
    if(a == 0 && b == 0){
        printf("Danh sach rong!\n");
    }
    printf("In gia tri a & b\n");
    printf("Gia tri a: %.2f\n", a);
    printf("Gia tri b: %.2f\n", b);
}

void menu(){
    printf("\n=== MENU LUA CHON ===\n");
    printf("1.Nhap gia tri a & b\n");
    printf("2.Swap gia tri a & b\n");
    printf("3.In gia tri a & b\n");
    printf("0.Thoat\n");
    printf("Nhap lua chon cua ban: ");
}
int main(){
    float a = 0,b = 0; //khởi tạo giá trị ban đầu
    int luaChon;
    int daNhap = 0; //cờ kiểm tra đã nhập chưa
    do{
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');

        switch(luaChon){
            case 1:
                printf("1.Nhap gia tri a & b\n");
                nhapNumber(&a, &b);
                break;
            case 2:
                printf("2.Swap gia tri a & b\n");
                swap(&a, &b);
                break;
            case 3:
                printf("3.In gia tri a & b\n");
                printNumber(a, b);
                break;
            case 0:
                printf("0.Thoat\n");
                printf(">>> Dang thoat. Tam Biet!");
                break;
            default: 
                printf("Nhap khong hop le! Nhap lai!\n");
        }
    }while(luaChon != 0);

    return 0;
}