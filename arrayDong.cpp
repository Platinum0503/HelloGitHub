#include <stdio.h>
#include <stdlib.h>

void taoMang(int **arr, int *n){
    printf("\nNhap n phan tu mang: ");
    scanf("%d", n); //caution

    if(*n <= 0){
        printf(">>> Loi! So luong khong hop le!\n");
        return;
    }       
    *arr = (int*)realloc(*arr, (*n) * sizeof(int)); //caution

    if(*arr == NULL){
        printf("Loi! cap phat bo nho");
        return;
    }
    for(int i = 0; i < *n;i++){
        printf("Nhap gia tri thu  %d ", i+1);
            scanf("%d", &(*arr)[i]);
    }
    while(getchar() != '\n');
    printf(">>> Da nhap %d phan tu thanh cong!\n", *n);
}

void themPhanTu(int **arr, int *n){
    *arr = (int*)realloc(*arr, (*n + 1) * sizeof(int)); //caution

    if(*arr == NULL){
        printf("Loi cap phat bo nho!\n");
        return;
    }

    printf("\n=== NHAP PHAN TU MOI ===\n");
    printf("Nhap gia tri: ");
    scanf("%d", &(*arr)[*n]); //caution
    (*n)++;
    printf("\nNhap thanh cong!\n");
}

void xoaPhanTu(int **arr, int *n, int k){
    printf("Nhap vi tri k (0-%d): ", *n - 1); //caution
    scanf("%d", &k);

    if(k < 0 || k >= *n){ //caution
        printf("vi tri khong hop le!\n");
        return;
    }

    for(int i = k; i < *n-1;i++){
        (*arr)[i] = (*arr)[i+1]; //caution
    }
    (*n)--;

    //thu small array
    *arr = (int*)realloc(*arr, (*n) * sizeof(int));

    printf(">>> Xoa thanh cong!\n");
}

void noiHaiMang(int **arr1, int *n1, int **arr2, int *n2){
    printf("nhap mang thu 2 cua ban\n");
    printf("Nhap n phan tu cua mang: ");
    scanf("%d", n2);

    if(*n2 <= 0){
        printf("Loi! so luong khong hop le\n");
        return;
    }

    *arr2 = (int*)malloc((*n2) * sizeof(int)); //caution

    if(*arr2 == NULL){
        printf("Loi! cap phat bo nho\n");
        return;
    }

    for(int i = 0; i < *n2;i++){
        printf("nhap gia tri thu %d ", i+1);
        scanf("%d", &(*arr2)[i]);
    }
    while(getchar() != '\n');

    //mở rộng mảng 1
    *arr1 = (int*)realloc(*arr1, (*n1) * sizeof(int));

    //copy array 2 in arr1
    for(int i = 0; i < *n2;i++){ //caution
        (*arr1)[*n1+i] = (*arr2)[i];
    }

    *n1 += *n2; //cập nhập kích thước

    printf(">>>Noi thanh cong! Mang co %d phan tu.\n", *n1);

    //giải phóng mảng 2
    free(*arr2);
    *arr2 = NULL;

}

void inMang(int arr[], int n){
    if(n == 0){
        printf("Mang rong!\n");
        return;
    }

    printf("\n=== DANH SACH MANG ===\n");
    for(int i = 0; i < n;i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void menu(){
    printf("\n=== MENU ===\n");
    printf("1.Tao mang\n");
    printf("2.Them 1 phan tu vao cuoi mang\n");
    printf("3.Xoa phan tu o vi tri k\n");
    printf("4.Noi 2 mang dong thanh 1 mang moi\n");
    printf("5.In Array\n");
    printf("0.Thoat\n");
}

int main(){
    int *arr = NULL; //sửa con trỏ NULL
    int n = 0;  //khỏi tạo = 0
    int *arr2 = NULL;
    int n2 = 0;
    int k = 0;
    int luaChon;

    do{
        menu();
        scanf("%d", &luaChon);
        
        switch(luaChon){
            case 1:
                printf("1.Tao mang\n");
                taoMang(&arr, &n);
                break;
            case 2:
                if(n == 0){
                    printf(">>> Chua co mang! Vui long tao mang truoc.\n");
                } else {
                    themPhanTu(&arr, &n);
                }
                break;
            case 3:
                if(n == 0){
                    printf(">>> Chua co mang! Vui long tao mang truoc.\n");
                } else {
                    xoaPhanTu(&arr, &n, k);
                }
                break;
            case 4: 
                if(n == 0){
                    printf(">>> Chua co mang! Vui long tao mang truoc.\n");
                } else {
                    noiHaiMang(&arr, &n, &arr2, &n2);
                }
                break;
            case 5: 
                inMang(arr, n);
                break;
            case 0:
                printf("0.Thoat\n");
                printf(">>> Dang thoat. Tam Biet!\n");
                break;
            default:
                printf("Nhap khong hop le! nhap lai\n");
                break;
        }

    }while(luaChon != 0);
    free(arr);
    free(arr2);
    
    return 0;
}