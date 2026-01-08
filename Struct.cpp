#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sinhVien {
    int id;  // Thêm ID
    char ten[50];
    int tuoi;
    float diem;
};
typedef struct sinhVien sinhVien;
// ========== LƯU VÀ ĐỌC FILE ==========

void luuFile(sinhVien sv[], int n){
    FILE *f = fopen("sinhvien.txt", "w");
    if(f == NULL){
        printf("Loi mo file!\n");
        return;
    }
    
    fprintf(f, "%d\n", n);

    for(int i = 0; i < n; i++){
        // Sửa: Thêm các tham số vào fprintf
        fprintf(f, "%d|%s|%d|%.2f\n", sv[i].id, sv[i].ten, sv[i].tuoi, sv[i].diem);
    }
    fclose(f);
    printf(">>> Da luu vao file!\n");
}

int docFile(sinhVien **sv){
    FILE *f = fopen("sinhvien.txt", "r");
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

    for(int i = 0; i < n; i++){
        // Sửa: Thêm các tham số vào fscanf
        fscanf(f, "%d|%[^|]|%d|%f\n", 
               &(*sv)[i].id, (*sv)[i].ten, &(*sv)[i].tuoi, &(*sv)[i].diem);
//**`%[^|]` nghĩa là:** Đọc TẤT CẢ ký tự **CHO ĐẾN KHI** gặp `|`
    }
    fclose(f);
    printf(">>> Da doc %d sinh vien tu file.\n", n);
    return n;
}

// ========== TÌM KIẾM ==========

int timKiemTheoID(sinhVien sv[], int n, int id){
    for(int i = 0; i < n; i++){
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
    ten[strcspn(ten, "\n")] = '\0';
    
    int found = 0;
    printf("\n=== KET QUA TIM KIEM ===\n");
    for(int i = 0; i < n; i++){
        if(strstr(sv[i].ten, ten) != NULL){
            printf("ID: %d | Ten: %s | Tuoi: %d | Diem: %.2f\n",
                   sv[i].id, sv[i].ten, sv[i].tuoi, sv[i].diem);
            found = 1;
        }
    }
    if(!found){
        printf(">>> Khong tim thay!\n");
    }
}

// ========== NHẬP SINH VIÊN ==========

void nhapSinhVien(sinhVien *sv, int id){
    sv->id = id;  // Gán ID
    
    printf("Nhap ten: ");
    fgets(sv->ten, sizeof(sv->ten), stdin);
    sv->ten[strcspn(sv->ten, "\n")] = '\0';

    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);

    printf("Nhap diem: ");
    scanf("%f", &sv->diem);

    while(getchar() != '\n');
}

// ========== THÊM SINH VIÊN ==========

void themSinhVien(sinhVien **sv, int *n){
    *sv = (sinhVien*)realloc(*sv, (*n + 1) * sizeof(sinhVien));
    
    if(*sv == NULL){
        printf("Loi cap phat!\n");
        return;
    }
    
    printf("\n=== THEM SINH VIEN MOI ===\n");
    
    // ID tự động tăng
    int newId = (*n == 0) ? 1 : (*sv)[*n - 1].id + 1;
    
    nhapSinhVien(&(*sv)[*n], newId);
    (*n)++;
    
    printf("\n>>> Da them thanh cong! (ID: %d)\n", newId);
}

// ========== SỬA THÔNG TIN ==========

void suaThongTin(sinhVien sv[], int n){
    int id;
    printf("Nhap ID can sua: ");
    scanf("%d", &id);
    while(getchar() != '\n');

    int viTri = timKiemTheoID(sv, n, id);

    if(viTri == -1){
        printf(">>> Khong tim thay ID %d\n", id);
        return;
    }
    
    printf("\n=== THONG TIN HIEN TAI ===\n");
    printf("ID: %d | Ten: %s | Tuoi: %d | Diem: %.2f\n",
           sv[viTri].id, sv[viTri].ten, sv[viTri].tuoi, sv[viTri].diem);
    
    printf("\n=== NHAP THONG TIN MOI ===\n");
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

// ========== XÓA SINH VIÊN ==========

void xoaSinhVien(sinhVien **sv, int *n){
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);
    while(getchar() != '\n');
    
    int viTri = timKiemTheoID(*sv, *n, id);
    
    if(viTri == -1){
        printf(">>> Khong tim thay ID %d\n", id);
        return;
    }
    
    printf("\n=== SINH VIEN SE BI XOA ===\n");
    printf("ID: %d | Ten: %s | Tuoi: %d | Diem: %.2f\n",
           (*sv)[viTri].id, (*sv)[viTri].ten, (*sv)[viTri].tuoi, (*sv)[viTri].diem);
    
    printf("\nXac nhan xoa? (y/n): ");
    char confirm = getchar();
    while(getchar() != '\n');
    
    if(confirm != 'y' && confirm != 'Y'){
        printf(">>> Huy xoa.\n");
        return;
    }

    // Dịch các phần tử về trước
    for(int i = viTri; i < *n - 1; i++){
        (*sv)[i] = (*sv)[i + 1];
    }
    (*n)--;

    // Thu nhỏ bộ nhớ
    *sv = (sinhVien*)realloc(*sv, (*n) * sizeof(sinhVien));
    
    printf("\n>>> Da xoa thanh cong!\n");
}

// ========== IN VÀ SẮP XẾP ==========

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
    for(int i = 1; i < n; i++){
        if(sv[i].diem > max){
            max = sv[i].diem;
            viTri = i;
        }
    }
    printf("\n=== Sinh vien co diem cao nhat ===\n");
    printf("ID: %d | Ten: %s | Tuoi: %d | Diem: %.2f\n",
           sv[viTri].id, sv[viTri].ten, sv[viTri].tuoi, sv[viTri].diem);
}

void sapXepTheoDiem(sinhVien sv[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(sv[j].diem < sv[j+1].diem){  // Giảm dần
                sinhVien temp = sv[j];
                sv[j] = sv[j+1];
                sv[j+1] = temp;
            }
        }
    }
    printf("\n>>> Da sap xep theo diem (giam dan).\n");
}

void inDanhSach(sinhVien sv[], int n){
    if(n == 0){
        printf("\n>>> Danh sach rong!\n");
        return;
    }
    
    printf("\n=== DANH SACH SINH VIEN ===\n");
    printf("%-5s %-20s %-6s %-6s\n", "ID", "Ten", "Tuoi", "Diem");
    printf("---------------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%-5d %-20s %-6d %.2f\n", 
               sv[i].id, sv[i].ten, sv[i].tuoi, sv[i].diem);
    }
}

// ========== MENU ==========

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

// ========== MAIN ==========

int main(){
    sinhVien *danhSach = NULL;
    int n = 0;
    int luaChon;

    // Đọc file khi khởi động
    n = docFile(&danhSach);

    do {
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');
        
        switch(luaChon) {
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
                printf("\n>>> Dang luu du lieu...\n");
                luuFile(danhSach, n);
                printf(">>> Tam biet!\n");
                break;
                
            default:
                printf(">>> Lua chon khong hop le!\n");
        }
        
    } while(luaChon != 0);
    
    // Giải phóng bộ nhớ
    free(danhSach);

    return 0;
}