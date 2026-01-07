#include <stdio.h>

int main(){
    int n;
    char str[50];

    printf("Nhap so: ");
    scanf("%d", &n);
    while(getchar() != '\n'); //caution to clear buffer

    printf("nhap chuoi: ");
    fgets(str, 50, stdin);
    
    printf("ket qua: %s\n", str);

}