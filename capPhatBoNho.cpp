#include <stdio.h>
#include <stdlib.h>

// free() giải phóng bộ nhớ động đã cấp phát bằng malloc, calloc, realloc
// tránh rò rỉ bộ nhớ (memory leak)

int main(){
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n *sizeof(int)); 

    //kiem tra cấp phát có thành công không
    if(arr == NULL){
        printf("Cap phat bo nho khong thanh cong!\n");
        return 1; //thoat chuong trinh voi ma loi
    }

    //buoc 3: input value
    printf("Nhap cac phan tu:\n");
    for(int i = 0;i < n;i++){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    //buoc 4: bubble sort
    for(int i = 0;i < n-1;i++){
        for(int j = 0;j < n-i-i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    //buoc 5: output value
    printf("Mang sau khi sap xep:\n");
    for(int i = 0; i < n;i++){
        printf("%d", arr[i]), printf(" ");
    }
    printf("\n");

    //buoc 6: giai phong bo nho
    free(arr);
    printf("Da giai phong bo nho!\n");

    return 0;
}