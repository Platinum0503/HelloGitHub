#include <stdio.h>
#include <stdlib.h>

// ========== THÊM PHẦN TỬ VÀO MẢNG ==========
void themPhanTu(float **arr, int *n){
    printf("\n=== Them phan tu vao mang ===\n");
    printf("Nhap so luong phan tu: ");
    scanf("%d", n);  // ← SỬA: Bỏ &
    
    if(*n <= 0){
        printf(">>> Loi! So luong khong hop le.\n");
        return;
    }
    
    // Cấp phát lại mảng
    *arr = (float*)realloc(*arr, (*n) * sizeof(float));
    
    if(*arr == NULL){
        printf(">>> Loi cap phat bo nho!\n");
        return;
    }
    
    // Nhập từng giá trị
    for(int i = 0; i < *n; i++){
        printf("Nhap gia tri thu %d: ", i + 1);
        scanf("%f", &(*arr)[i]);  // ← LƯU vào mảng
    }
    while(getchar() != '\n');
    
    printf(">>> Da nhap %d phan tu thanh cong!\n", *n);
}

// ========== TĂNG SỐ LƯỢNG LÊN 10 ==========
void tangGiaTri(int *n){
    if(*n == 0){
        printf(">>> Chua co phan tu nao! Vui long nhap truoc.\n");
        return;
    }
    
    printf("So luong truoc: %d\n", *n);
    *n += 10;  // ← SỬA: Tăng lên 10
    printf("So luong sau: %d\n", *n);
    printf(">>> Da tang so luong len 10!\n");
}

// ========== IN MẢNG ==========
void printArray(float arr[], int n){
    if(n == 0){
        printf("\n>>> Mang rong!\n");
        return;
    }
    
    printf("\n=== DANH SACH MANG ===\n");
    for(int i = 0; i < n; i++){
        printf("arr[%d] = %.2f\n", i, arr[i]);  // ← SỬA: %.2f
    }
}

// ========== MENU ==========
void menu(){
    printf("\n            MENU LUA CHON              \n");
    printf("  1. Nhap vao mang                     \n");
    printf("  2. Tang so luong mang len 10         \n");
    printf("  3. In mang                           \n");
    printf("  0. Thoat                              \n");
    printf("Chon chuc nang: ");
}

// ========== MAIN ==========
int main(){
    float *danhSach = NULL;  // ← SỬA: float* thay vì array*
    int luaChon;
    int n = 0;  // ← SỬA: Khởi tạo = 0
    
    do {
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');

        switch(luaChon){
            case 1:
                themPhanTu(&danhSach, &n);  // ← SỬA: &n
                break;
                
            case 2:
                tangGiaTri(&n);
                break;
                
            case 3:
                printArray(danhSach, n);
                break;
                
            case 0:
                printf("\n>>> Dang thoat. Tam biet!\n");
                break;
                
            default: 
                printf(">>> Nhap khong hop le! Vui long chon 0-3.\n");
        }

    } while(luaChon != 0);

    // Giải phóng bộ nhớ
    free(danhSach);
    
    return 0;
}