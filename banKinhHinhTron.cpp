#include <stdio.h>
#include <math.h>
int main(){
    const float pi = 3.14;
    float banKinh;
    printf("=== BAN KINH HINH TRON ===\n");
    printf("Nhap ban kinh (r): ");
    scanf("%f", &banKinh);

    float dienTich = pi*pow(banKinh, 2);
    float chuVi = 2*pi*banKinh;

    printf("\ndien tich: %.2f", dienTich);
    printf("\nchu vi: %.2f", chuVi);

    return 0;
}