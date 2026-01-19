#include <stdio.h>

int main(){ 
    float cd, cr;
    printf("Nhap Chieu dai: ");
    scanf("%f", &cd);
    while(getchar() != '\n');
    printf("Nhap Chieu rong: ");
    scanf("%f", &cr);

    printf("\n=== HINH CHU NHAT ===\n");
    float dienTich = cd * cr;
    printf("Dien tich: %.2f", dienTich);
    float chuVi = (cd + cr)*2;
    printf("\nChu vi: %.2f", chuVi);
    return 0;
}