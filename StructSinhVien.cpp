#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sinhVien {
    int id;
    char ten[50];
    int tuoi;
    float diem;
};
typedef struct sinhVien sinhVien;

//luu va doc file
void luuFile(sinhVien sv[], int n){
    FILE *f = fopen("sinhVien1.txt", "w");
    if(f == NULL){
        printf("loi mo file!\n");
        return;
    }

    fprintf(f, "%d\n", n);

    for(int i = 0; i < n;i++){
        fprintf(f, "%d|%s|%d|%.2f\n", sv[i].id, sv[i].ten, sv[i].tuoi, sv[i].diem);
    }
    fclose(f);
    printf(">>> Da luu vao file!\n");
}

int docFile(sinhVien **sv){
    FILE *f = fopen("sinhVien1.txt", "r");
    if(f == NULL){
        printf(">>> Khong tim thay file, bat dau danh sach moi.\n");
        return 0;
    }

    int n;
    fscanf(f, "%d\n", &n);

    *sv = (sinhVien*)malloc(n * sizeof(sinhVien));
    if(*sv == NULL){
        printf("Loi cap phat!\n");
        fclose(f);
        return 0;
    }

    for(int i = 0; i < n;i++){
        fscanf(f, "%d|%[^|]|%d|%f\n",
        &(*sv)[i].id, (*sv)[i].ten, &(*sv)[i].tuoi, &(*sv)[i].diem);
    }
    fclose(f);
    printf(">>> Da doc %d sinh vien tu file.\n", n);
    return n;
}

int timKiemTheoID(sinhVien sv[], int n, int id){
    for(int i = 0; i < n;i++){
        if(sv[i].id == id){
            return i;
        }
    }
    return -1;
}

void timKiemTheoTen(sinhVien sv[], int n){
    char ten[50];
    printf("Nhap ten can tim: ");
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0'; //caution //loai bo xuong dong

    int found = 0;
    printf("\n=== KET QUA TIM KIEM ===\n");
    for(int i = 0; i < n;i++){
        if(strstr(sv[i].ten, ten) != NULL){
            printf("ID: %d | Ten: %s | Tuoi: %d | Diem: %.2f\n",
            sv[i].id, sv[i].ten, sv[i].tuoi, sv[i].diem);
            found = 1;
        }
    }
    if(!found){
        printf(">>> Khong tim thay sinh vien voi ten \"%s\"\n", ten);
    }
}

void nhapSinhVien(sinhVien *sv, int id){
    sv->id = id; //gán ID
    printf("Nhap ten: ");
    fgets(sv->ten, sizeof(sv->ten), stdin);
    sv->ten[strcspn(sv->ten, "\n")] = '\0';

    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);

    printf("Nhap diem: ");
    scanf("%f", &sv->diem);

    while(getchar() != '\n');
}

void themSinhVien(sinhVien **sv, int *n){
    *sv = (sinhVien*)realloc(*sv, (*n + 1) * sizeof(sinhVien));

    if(*sv == NULL){
        printf("Loi cap phat bo nho!\n");
        return;
    }

    printf("=== NHAP THONG TIN SINH VIEN MOI ===\n");
    //ID tu dong tang
    int newId = (*n == 0) ? 1 : (*sv)[*n - 1].id + 1; //caution

    nhapSinhVien(&(*sv)[*n], newId);
    (*n)++;

    printf(">>> Da them thanh cong! (ID: %d)\n", newId);
}

void suaThongTin(sinhVien sv[], int n){
    int id;
    printf("Nhap ID can sua: ");
    scanf("%d", &id);
    while(getchar() != '\n');

    int viTri = timKiemTheoID(sv, n, id);

    if(viTri == -1){
        printf(">>> khong tim thay ID %d\n", id);
        return;
    }

    printf("\n=== THONG TIN HIEN TAI ===\n");
    printf("ID: %d | Ten: %s | Tuoi: %d | Diem: %.2f\n",
           sv[viTri].id, sv[viTri].ten, sv[viTri].tuoi, sv[viTri].diem);
    
    printf("\n=== NHAP THONG TIN MOIW ===\n");
    printf("Nhap ten moi: ");
    fgets(sv[viTri].ten, sizeof(sv[viTri].ten), stdin);
    sv[viTri].ten[strcspn(sv[viTri].ten, "\n")] = '\0';
    
    printf("Nhap tuoi moi: ");
    scanf("%d", &sv[viTri].tuoi);

    printf("Nhap diem moi: ");
    scanf("%f", &sv[viTri].diem);

    while(getchar() != '\n');
    printf("\n>>> Da sua thanh cong!\n");
}

void xoaSinhVien(sinhVien **sv, int *n){
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);
    while(getchar() != '\n');

    int viTri = timKiemTheoID(*sv, *n, id);

    if(viTri == -1){
        printf(">>> khong tim thay ID %d\n", id);
        return;
    }

    printf("\n=== SINH VIEN SE BI XOA ===\n");
    printf("ID: %d | Ten: %s | Tuoi: %d | Diem: %.2f\n",
    (*sv)[viTri].id, (*sv)[viTri].ten, (*sv)[viTri].tuoi, (*sv)[viTri].diem);

    printf("Xac nhan xoa (y/n): ");
    char confirm = getchar();
    while(getchar() != '\n');

    if(confirm != 'y' && confirm != 'Y'){
        printf(">>> Huy xoa.\n");
        return;
    }

    //dịch các phần tử sau lên trước
    for(int i = viTri; i < *n-1;i++){
        (*sv)[i] = (*sv)[i+1];
    }
    (*n)--;

    //thu nhỏ bộ nhớ
    *sv = (sinhVien*)realloc(*sv, (*n) * sizeof(sinhVien));
    printf(">>> Da xoa thanh cong!\n");
}

void printStudent(sinhVien sv){
    printf("\n=== Thong tin sinh vien ===\n");
    printf("ID: %d\n", sv.id);
    printf("Ten: %s\n", sv.ten);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("Diem: %.2f\n", sv.diem);
}

void diemCaoNhat(sinhVien sv[], int n){
    if(n == 0){
        printf("Khong co sinh vien nao!\n");
        return;
    }

    int viTri = 0;
    float max = sv[0].diem;
    for(int i = 1;i < n;i++){
        if(sv[i].diem > max){
            max = sv[i].diem;
            viTri = i;
        }
    }
    printf("\n=== SINH VIEN CO DIEM CAO NHAT ===\n");
    printf("ID: %d | Ten: %s | Tuoi: %d | Diem: %.2f\n",
    sv[viTri].id, sv[viTri].ten, sv[viTri].tuoi, sv[viTri].diem);   
}

void sapXepTheoDiem(sinhVien sv[], int n){
    for(int i = 0; i < n-1;i++){
        for(int j = i+1;j < n;j++){
            if(sv[i].diem < sv[j].diem){
                sinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    printf("\n>>> Da sap xep theo diem (giam dan).\n");
}

void inDanhSach(sinhVien sv[], int n){
    if(n == 0){
        printf("\n===Danh sach rong!===\n");
        return;
    }

    printf("\n===danh sach sinh vien===\n");
    for(int i = 0; i < n;i++){
        printf("ID: %d | Ten: %s | Tuoi: %d | Diem: %.2f\n",
        sv[i].id, sv[i].ten, sv[i].tuoi, sv[i].diem);
    }
}

void menu(){
    printf("\n");
    printf("     QUAN LY SINH VIEN - MENU          \n");
    printf("  1. Them sinh vien                    \n");
    printf("  2. Hien thi danh sach                \n");
    printf("  3. Tim kiem theo ten                 \n");
    printf("  4. Sua thong tin sinh vien           \n");
    printf("  5. Xoa sinh vien                     \n");
    printf("  6. Sap xep theo diem                 \n");
    printf("  7. Luu vao file                      \n");
    printf("  0. Thoat (tu dong luu)               \n");
    printf("Chon chuc nang: ");
}

int main(){
    sinhVien *danhSach = NULL; //caution
    int n = 0;  //caution
    int luaChon;

    // Đọc file khi khởi động
    n = docFile(&danhSach);

    do {
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');

        switch(luaChon){
            case 1:
                themSinhVien(&danhSach, &n);
                break;
            case 2: 
                inDanhSach(danhSach, n);
                break;
            case 3: 
                timKiemTheoTen(danhSach, n);
                break;
            case 4:
                suaThongTin(danhSach, n);
                break;
            case 5:
                xoaSinhVien(&danhSach, &n);
                break;
            case 6: 
                sapXepTheoDiem(danhSach, n);
                inDanhSach(danhSach, n);
                break;
            case 7: 
                luuFile(danhSach, n);
                break;
            case 0: 
                luuFile(danhSach, n);
                printf(">>> Thoat chuong trinh. Tam Biet!\n");
                break;
            default: 
                printf(">>> Lua chon khong hop le. Vui long chon lai!\n");
        }   
    }while(luaChon != 0);

    // Giải phóng bộ nhớ
    free(danhSach);

}