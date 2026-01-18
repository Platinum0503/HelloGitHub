#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sinhVien {
    char ten[50];
    int tuoi;
};
typedef struct sinhVien sinhVien;

void luuFile(sinhVien sv[], int n){
    FILE *f = fopen("sinhVien2.txt", "w"); // "w" = Write mode (Chế độ GHI)
    if(f == NULL){
        printf("Loi mo file!\n");
        return;
    }

    fprintf(f, "%d\n", n);
    for(int i = 0; i < n;i++){
        fprintf(f, "%s|%d\n", sv[i].ten, sv[i].tuoi);
    }
    fclose(f);
    printf(">>> Da luu vao file!\n");
}

int docFile(sinhVien **sv){
    FILE *f = fopen("sinhVien2.txt", "r");  //"r"Read (Đọc)Mở file để ĐỌC. File phải tồn tại.
    if(f == NULL){
        printf(">>> Khong tim thay file, bat dau danh sach moi.\n");
        return 0; //caution
    }

    int n;
    fscanf(f, "%d\n", &n);

    *sv = (sinhVien*)malloc(n * sizeof(sinhVien));
    if(*sv == NULL){
        printf("Loi cap phat!\n");
        fclose(f);
        return 0; //caution
    }

    for(int i = 0; i < n;i++){
        fscanf(f, "%s [^|]|%d\n",
            &(*sv)[i].ten, (*sv)[i].tuoi); //caution
    }
    fclose(f);
    printf(">>> Da doc %d sinh vien tu file.\n", n);
    return n; //caution
}

void inputSttuden(sinhVien *sv){
    printf("nhap ten: ");
    fgets(sv->ten, sizeof(sv->ten), stdin);
    sv->ten[strcspn(sv->ten, "\n")] = '\0';

    printf(("nhap tuoi: "));
    scanf("%d", &sv->tuoi);
    while(getchar() != '\n');
}

void printStudent(sinhVien sv){
    printf("\n=== Thong tin sinh vien ===\n");
    printf("Ten: %s\n", sv.ten);
    printf("Tuoi: %d\n", sv.tuoi);
}

void Menu(){
    printf("\n");
    printf("     QUAN LY SINH VIEN - MENU          \n");
    printf("  1. Them sinh vien                    \n");
    printf("  2. Luu vao file                      \n");
    printf("  3. Doc tu file                       \n");
    printf("  4. Hien thi sinh vien                \n");
    printf("  0. Thoat                             \n");
    printf("Chon chuc nang: ");

}

int main(){
    sinhVien *danhSach = NULL;
    int n = 0;
    int luaChon;

    n = docFile(&danhSach);
    
    do {
        Menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');
        switch(luaChon){
            case 1:
                danhSach = (sinhVien*)realloc(danhSach, (n + 1) * sizeof(sinhVien));
                if(danhSach == NULL){
                    printf("Loi cap phat bo nho!\n");
                    break;
                }
                inputSttuden(&danhSach[n]);
                n++;
                break;
            case 2: 
                luuFile(danhSach, n);
                break;
            case 3: 
                n = docFile(&danhSach);
                break;
            case 4: 
                for(int i = 0; i < n;i++){
                    printStudent(danhSach[i]);
                }
                break;
            case 0:
                luuFile(danhSach, n);
                free(danhSach);
                printf(">>> Da thoat chuong trinh.\n");
                break;
            }

    }while(luaChon != 0);

    return 0;
}