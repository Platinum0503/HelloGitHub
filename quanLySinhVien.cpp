#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    typedef struct sinhVien{
        int maSV;
        char tenSV[50];
        float diemTB;
        char lop[20];
    } sinhVien;

    typedef struct monHoc{
        int maMH;
        int maSV;
        char tenMH[50];
        float diem;
    } monHoc;
    // KHAI BÁO HÀM
    int timKiemSinhVienTheoMaSV(sinhVien sv[], int n, int maSV);

    void luuFileSinhVien(sinhVien sv[], int n){
        FILE *f = fopen("quanLySinhVien.txt", "w");
        if(f == NULL){
            printf("Loi mo file! tao file moi");
            return;
        }
        fprintf(f, "%d\n", n);
        for(int i = 0; i < n;i++){
            fprintf(f, "%d|%s|%.2f|%s\n", sv[i].maSV, sv[i].tenSV, sv[i].diemTB, sv[i].lop);
        }
        fclose(f);
        printf(">>>Da luu file thanh cong!\n");
    }
    int docFileSinhVien(sinhVien **sv){
        FILE *f = fopen("quanLySinhVien.txt", "r");
        if(f == NULL){
            printf("Loi mo file!");
            return 0;
        }
        int n;
        fscanf(f, "%d\n", &n);
        *sv = (sinhVien*)malloc(n * sizeof(sinhVien));
        for(int i = 0; i < n;i++){
            fscanf(f, "%d|%[^|]|%f|%[^|]\n", &(*sv)[i].maSV, (*sv)[i].tenSV, &(*sv)[i].diemTB, (*sv)[i].lop);
        }
        fclose(f);
        printf(">>>Da doc %d sinh vien trong file!", n);
        return n;
    }
    void nhapSinhVien(sinhVien *sv, int maSV){ //caution sv[] la array
        sv->maSV = maSV; //dùng -> (sv là con trỏ đơn)
        printf("Nhap ten sinh vien: ");
        fgets(sv->tenSV, sizeof(sv->tenSV), stdin);
        sv->tenSV[strcspn(sv->tenSV, "\n")] = '\0';

        printf("Nhap diem trung binh: ");
        scanf("%f", &sv->diemTB);
        while(getchar() != '\n');

        printf("Nhap lop: ");
        fgets(sv->lop, sizeof(sv->lop), stdin);
        sv->lop[strcspn(sv->lop, "\n")] = '\0';
        printf(">>>Nhap thanh cong sinh vien!\n");
    }
    int timKiemSinhVienTheoMaSV(sinhVien sv[], int n, int maSV){
        for(int i = 0;i < n;i++){
            if(sv[i].maSV == maSV){
                return i;
            }
        }
        return -1;
    }
    void themSinhVien(sinhVien **sv, int *n){
        *sv = (sinhVien*)realloc(*sv, (*n+1) * sizeof(sinhVien));
        if(*sv == NULL){
            printf("Loi cap phat bo nho!\n");
            return;
        }
        printf("\n=== THEM SINH VIEN MOI ===\n");
        int newMaSV = (*n == 0) ? 1: (*sv)[*n-1].maSV + 1;
        nhapSinhVien(&(*sv)[*n], newMaSV);//caution
        (*n)++;
        printf(">>>Da them sinh vien thanh cong! (Ma sv: %d)\n", newMaSV);
    }
    void xoaSinhVien(sinhVien **sv, int *n){
        if(*n == 0){ //caution
            printf("Danh sach trong! khong so sinh vien nao!");
            return;
        }
        int maSV;
        printf("Nhap ma sinh vien muon xoa: ");
        scanf("%d", &maSV);
        while(getchar() != '\n');
        int viTri = timKiemSinhVienTheoMaSV(*sv, *n, maSV);
        if(viTri == -1){ //caution
            printf("Khong tim thay sinh vien co ma %d", maSV);
            return;
        }
        printf("\n=== THONG TIN SINH VIEN HIEN TAI ===\n");
        printf("%d|%s|%f|%s", (*sv)[viTri].maSV, (*sv)[viTri].tenSV, (*sv)[viTri].diemTB, (*sv)[viTri].lop);
        printf("Xac Nhan (Y/N): ");
        char confirm = getchar();
        while(getchar() != '\n');
        if(confirm != 'y' && confirm != 'Y'){ //caution use && not || 
            printf("Huy xoa\n");
            return;
        }
        for(int i = viTri; i < *n-1;i++){ //caution
            (*sv)[i] = (*sv)[i+1];
        }
        (*n)--;
        printf(">>> Xoa thanh cong sinh vien co ma %d", maSV);
    }
    void suaSinhVien(sinhVien sv[], int n){
        int maSV;
        printf("Nhap ma sinh vien: ");
        scanf("%d", &maSV);
        while(getchar() != '\n');
        int viTri = timKiemSinhVienTheoMaSV(sv, n, maSV);
        if(maSV == -1){ //caution
            printf("khong tim thay sinh vien co ma %d", maSV);
            return;
        }
        printf("\n=== THONG TIN SINH VIEN HIEN TAI ===\n");
        printf("%d|%s|%f|%s", sv[viTri].maSV, sv[viTri].tenSV, sv[viTri].diemTB, sv[viTri].lop);
        printf("Xac nhan muon sua thong tin(y/n): ");
        char confirm = getchar();
        while(getchar() != '\n');
        if(confirm != 'y' && confirm != 'Y'){ //caution use && not ||
            printf("Huy thanh cong!");
            return;
        }
        printf("Nhap ten sinh vien moi: ");
        fgets(sv[viTri].tenSV, sizeof(sv[viTri].tenSV), stdin);
        sv[viTri].tenSV[strcspn(sv[viTri].tenSV, "\n")] = '\0';

        printf("Nhap diem trung binh: ");
        scanf("%f", &sv[viTri].diemTB);
        while(getchar() != '\n');

        printf("Nhap lop: ");
        fgets(sv[viTri].lop, sizeof(sv[viTri].lop), stdin);
        sv[viTri].lop[strcspn(sv[viTri].lop, "\n")] = '\0';
        printf(">>>Sua thanh cong!\n");
    }
    void hienThiSinhVien(sinhVien sv[], int n){
        if(n == 0){
            printf("Chua co sinh vien nao\b");
            return;
        }
        printf("\n%-10s %-30s %-15s %-20s\n", "Ma SV", "Ten SV", "Diem TB", "Lop");
        for(int i = 0; i < n;i++){
            printf("%-10d %-30s %-15.2f %-20s\n",
            sv[i].maSV, sv[i].tenSV, sv[i].diemTB, sv[i].lop);
        }
    }
    void luuFileMonHoc(monHoc mh[], int n){
        FILE *f = fopen("monHoc.txt", "w");
        if(f == NULL){
            printf("Loi mo file! tao file moi");
            return;
        }
        fprintf(f, "%d\n", n);
        for(int i = 0;i < n;i++){
            fprintf(f, "%d|%d|%s|%.2f\n", mh[i].maMH, mh[i].maSV, mh[i].tenMH, mh[i].diem);
        }
        fclose(f);
        printf(">>>Da luu %d sinh vien vao file!", n);
    }
    int docFileMonHoc(monHoc **mh){
        FILE *f = fopen("monHoc.txt", "r");
        if(f == NULL){
            printf("Loi mo file!");
            return 0;
        }
        int n;
        fscanf(f, "%d\n", &n);
        *mh = (monHoc*)malloc(n * sizeof(monHoc)); //use malloc thay vi realloc
        for(int i = 0; i < n;i++){
            fscanf(f, "%d|%d|%[^|]|%f\n", &(*mh)[i].maMH, &(*mh)[i].maSV, (*mh)[i].tenMH, &(*mh)[i].diem);
        }
        fclose(f);
        printf(">>>Da doc %d sinh vien tu file!", n);
        return n;
    }
    void nhapDiemMonHoc(monHoc **mh, int *soMH, sinhVien *sv, int soSV){// caution
        int maSV;
        printf("\n=== NHAP DIEM MON HOC ===\n");
        printf("Nhap ma sinh vien: ");
        scanf("%d", &maSV); //trong scan k có \n
        while(getchar() != '\n');
        int viTri = timKiemSinhVienTheoMaSV(sv, soSV, maSV); //caution
        if(viTri == -1){
            printf("Khong tim thay sinh vien co ma %d", maSV);
            return;
        }
    
        printf("Sinh vien: %s\n", sv[viTri].tenSV);

        *mh = (monHoc*)realloc(*mh, (*soMH+1) * sizeof(monHoc));
        if(*mh == NULL){
            printf("Loi cap phat bo nho!");
            return;
        }
        int maMH = (*soMH == 0) ? 1 : (*mh)[*soMH-1].maMH + 1; //caution
        (*mh)[*soMH].maMH = maMH;
        (*mh)[*soMH].maSV = maSV;

        printf("Nhap ten mon hoc: ");
        fgets((*mh)[*soMH].tenMH, sizeof((*mh)[*soMH].tenMH), stdin);
        (*mh)[*soMH].tenMH[strcspn((*mh)[*soMH].tenMH, "\n")] = '\0';

        printf("Nhap diem: ");
        scanf("%f", &(*mh)[*soMH].diem);
        while(getchar() != '\n');

        (*soMH)++;
        printf(">>>Da nhap diem thanh cong!\n");
    }
    void tinhDiemTrungBinh(sinhVien *sv, int soSV, monHoc *mh, int soMH){
        int maSV;
        printf("\n=== TINH DIEM TRUNG BINH ===\n");
        printf("Nhap ma sinh vien: ");
        scanf("%d", &maSV);
        while(getchar() != '\n');

        int viTri = timKiemSinhVienTheoMaSV(sv, soSV ,maSV);
        if(viTri == -1){
            printf("Khong tim thay sinh vien\n");
            return;
        }

        float tongDiem = 0;
        int demMon = 0;

        printf("\n%-30s %-10s\n", "Mon Hoc", "Diem");
        for(int i = 0; i < soMH;i++){
            if(mh[i].maSV == maSV){
                printf("%-30s %-10.2f\n", mh[i].tenMH, mh[i].diem);
                tongDiem += mh[i].diem;
                demMon++;
            }
        }
        if(demMon == 0){
            printf("sinh vien chua co diem mon nao\n");
            return;
        }
        sv[viTri].diemTB = tongDiem/demMon;
        printf("Diem trung binh: %.2f\n", sv[viTri].diemTB);
    }
    void xepLoaiHocLuc(sinhVien sv[], int n){
        if(n == 0){
            printf("Chua co sinh vien nao\n");
            return;
        }
        printf("\n=== XEP LOAI HOC LUC ===\n");
        printf("%-10s %-30s %-15s %-15s\n", "Ma SV", "Ten SV", "Diem TB", "Xep Loai");
        for(int i = 0; i < n;i++){
            char *xepLoai;
            if(sv[i].diemTB >= 8.5) xepLoai = "Gioi";
            else if(sv[i].diemTB >= 7.0) xepLoai = "Kha";
            else if(sv[i].diemTB >5.5) xepLoai = "Trung Binh";
            else xepLoai = "Yeu";
            printf("%-10d %-30s %-15.2f %-15s\n", 
            sv[i].maSV, sv[i].tenSV, sv[i].diemTB, xepLoai);
        }
    }
    void menu(){
        printf("\n=== MENU ===\n");
        printf("1. Them sinh vien\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Sua sinh vien\n");
        printf("4. Hien thi sinh vien\n");
        printf("5. Nhap diem mon hoc\n");
        printf("6. Tinh diem trung binh\n");
        printf("7. Xep loai hoc luc\n");
        printf("8. Luu file\n");
        printf("0.Thoat\n");
        printf("Nhap lua chon cua ban: ");
    }
    int main(){
        sinhVien *sv = NULL;
        monHoc *mh = NULL;
        int luaChon;
        int soSV = 0;
        int soMH = 0;
        soSV = docFileSinhVien(&sv);
        soMH = docFileMonHoc(&mh);
        
        do {
            menu();
            scanf("%d", &luaChon);
            while(getchar() != '\n');
            switch(luaChon){
                case 1:
                    themSinhVien(&sv, &soSV);
                    break;  
                case 2:
                    xoaSinhVien(&sv, &soSV);
                    break;
                case 3: 
                    suaSinhVien(sv, soSV);
                    break;
                case 4: 
                    hienThiSinhVien(sv, soSV);
                    break;
                case 5: 
                    nhapDiemMonHoc(&mh, &soMH, sv, soSV);
                    break;  
                case 6: 
                    tinhDiemTrungBinh(sv, soSV, mh, soMH);
                    break;
                case 7:
                    xepLoaiHocLuc(sv, soSV);
                    break;
                case 8:
                    luuFileSinhVien(sv, soSV);
                    luuFileMonHoc(mh, soMH);
                    break;
                case 0: 
                    printf("Tam biet!\n");
                    break;
                default:
                    printf("Lua chon khong hop le! nhap lai: ");
            }
        }while(luaChon != 0);
        free(sv);
        free(mh);
        return 0;
    }