#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sinhVien {
    char ten[50];
    int tuoi;
    float diem;
};
typedef struct sinhVien sinhVien; //để gọi ngắn gọn hơn

void nhapSinhVien(sinhVien *sv){
   printf("Nhap ten: ");
   fgets(sv->ten, sizeof(sv->ten), stdin);
    //delete \n
    sv->ten[strcspn(sv->ten, "\n")] = 0; //caution

    printf("Nhap tuoi:");
    scanf("%d", &sv->tuoi);

    printf("nhap diem:");
    scanf("%f", &sv->diem);

    //delete buffer
    while(getchar() != '\n'); //caution
}

void printStudent(sinhVien sv){
    printf("\n=== Thong tin sinh vien ===\n");
    printf("Ten: %s\n", sv.ten);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("Diem: %.2f\n", sv.diem);
}

void diemCaoNhat(sinhVien sv[], int n){
    if(n == 0){
        printf("Khong co sinh vien nao!\n");
        return;
    }

    int nameSv;
    float max = sv[0].diem;
    for(int i = 1;i < n;i++){
        if(sv[i].diem > max){
            max = sv[i].diem;
            nameSv = i;
        }
    }
    printf("\n=== Sinh vien co diem cao nhat ===\n");
    printf("Ten: %s\n", sv[nameSv].ten);
    printf("Tuoi: %d\n", sv[nameSv].tuoi);
    printf("Diem: %.2f\n", max);
}

void sapXepTheoDiem(sinhVien sv[], int n){
    for(int i = 0; i < n-1;i++){
        for(int j = 0;j < n-i-1;j++){
            if(sv[j].diem > sv[j+1].diem){
                sinhVien temp = sv[j];
                sv[j] = sv[j+1];
                sv[j+1] = temp;
            }
        }
    }
}

void inDanhSach(sinhVien sv[], int n){
    printf("\n=== Danh sach sinh vien ===\n");
    for(int i = 0; i < n;i++){
        printf("\nSinh vien %d:\n", i+1);
        printf("ten: %s\n", sv[i].ten);
        printf("Tuoi: %d\n", sv[i].tuoi);
        printf("Diem: %.2f\n", sv[i].diem);
    }
}

int main(){
    int n;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    while(getchar() != '\n'); //delete buffer

    //cấp phát động mảng sinh viên
    sinhVien *sv = (sinhVien*) malloc(n * sizeof(sinhVien));

    if(sv == NULL){
        printf("Cap phat bo nho khong thanh cong!\n");
        return 1;
    }

    for(int i = 0; i < n;i++){
        printf("\nNhap thong tin sinh vien thu %d:\n", i+1);
        nhapSinhVien(&sv[i]);
    }  

    //in danh sach ban đầu
    inDanhSach(sv, n);

    //search diem cao nhat
    diemCaoNhat(sv, n);
    
    //sap xep theo diem
    sapXepTheoDiem(sv, n);
    printf("\n=== Danh sach sinh vien sau khi sap xep theo diem ===\n");
    inDanhSach(sv, n);

    //giai phong bo nho
    free(sv);
    printf("\nDa giai phong bo nho!\n");

    return 0;
}