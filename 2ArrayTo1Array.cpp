#include <stdio.h>
#include <stdlib.h>

int main(){
    int n1;
    int n2;

    printf("Nhap so luong phan tu mang 1: ");
    scanf("%d", &n1);
    printf("Nhap so luong phan tu mang 2: ");   
    scanf("%d", &n2);
    
    int *arr1 = (int*)malloc(n1 * sizeof(int));
    int *arr2 = (int*)malloc(n2 * sizeof(int));

    if(arr1 == NULL || arr2 == NULL){
        printf("Cap phat bo nho khong thanh cong!\n");
        return 1;
    }

    for(int i = 0; i < n1;i++){
        printf("Nhap phan tu arr1[%d]: ", i);
        scanf("%d", &arr1[i]);
    }

    for(int i = 0; i < n2;i++){
        printf("Nhap phan tu arr2[%d]: ", i);
        scanf("%d", &arr2[i]);
    }

    printf("Mang 1:\n");
    for(int i = 0; i < n1;i++){
        printf("%d", arr1[i]);
    }

    printf("\nMang 2:\n");
    for(int i = 0;i < n2;i++){
        printf("%d", arr2[i]);
    }

    int *arr3 = (int*)malloc((n1 + n2) * sizeof(int));
    if(arr3 == NULL){
        printf("Cap phat bo nho khong thanh cong!\n");
        free(arr1);
        free(arr2);
        return 1;
    }

    // Bước 3: Sao chép arr1 vào arr3
    for(int i = 0; i < n1;i++){
        arr3[i] = arr1[i];
    }

    // Bước 4: Sao chép arr2 vào arr3 (tiếp sau arr1)
    for(int i = 0; i < n2;i++){
        arr3[n1 + i] = arr2[i];
    }

    printf("\nMang sau khi ghep:\n");
    for(int i = 0; i < n1 + n2;i++){
        printf("%d", arr3[i]);
    }

    free(arr1);
    free(arr2);
    free(arr3);
}