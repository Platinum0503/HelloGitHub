#include <stdio.h>

int main(){
    float diem;
    printf("Nhap diem cua ban: ");
    scanf("%f", &diem);
    if(diem < 5){
        printf("Hoc lai");
    } else {
        printf("Dat yeu cau\n");
        printf("Qua mon");
    } 
    return 0;
}