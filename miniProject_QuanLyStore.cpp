#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sanPham{
    int maSP;
    char tenSP[50];
    float gia;
    int soLuong;
} sanPham;

typedef struct hoaDon{
    int maHD;
    int maSP;
    int soLuongMua;
    float thanhTien;
} hoaDon;  
int timKiemTheoMaSP(sanPham sp[], int n, int maSP){
    for(int i = 0; i < n;i++){
        if(sp[i].maSP == maSP){
            return i;
        }
    }
    return -1;
}
void luuFileSanPham(sanPham sp[], int n){
    FILE *f = fopen("sanPham.txt", "w");
    if(f == NULL){
        printf("loi mo file!");
        return;
    }
    fprintf(f,"%d\n", n);
    for(int i = 0;i < n;i++){
        fprintf(f, "%d|%s|%.2f|%d\n", sp[i].maSP, sp[i].tenSP, sp[i].gia, sp[i].soLuong);
    }
    fclose(f);
    printf(">>>Da luu file");
}
int docFileSanPham(sanPham **sp){
    FILE *f = fopen("sanPham.txt", "r");
    if(f == NULL){
        printf("Loi mo file! tao file moi");
        return 0;
    }
    int n;
    fscanf(f, "%d\n", &n);
    *sp = (sanPham*)malloc(n * sizeof(sanPham));
    if(*sp == NULL){
        printf("Loi cap phat bo nho\n");
        fclose(f);
        return 0;
    }
    for(int i = 0; i < n;i++){
        fscanf(f, "%d|%[^|]|%f|%d", &(*sp)[i].maSP, (*sp)[i].tenSP, &(*sp)[i].gia, &(*sp)[i].soLuong);
    }
    fclose(f);
    printf(">>>Da doc %d san pham trong file", n);
    return n;
}
void NhapSanPham(sanPham *sp, int maSP){
    sp->maSP = maSP;
    printf("Nhap ten san pham: ");
    fgets(sp->tenSP, sizeof(sp->tenSP), stdin);
    sp->tenSP[strcspn(sp->tenSP, "\n")] = '\0';

    printf("Nhap gia: ");
    scanf("%f", &sp->gia);
    while(getchar() != '\n');
    printf("Nhap so luong: ");
    scanf("%d", &sp->soLuong);
    while(getchar() != '\n');
}
void themSanPham(sanPham **sp, int *n){
    *sp = (sanPham*)realloc(*sp, (*n+1) * sizeof(sanPham));
    if(*sp == NULL){
        printf("Loi cap phat bo nho!");
        return;
    }
    printf("\n=== NHAP SAN PHAM MOI ===\n");
    int newMaSP = (*n == 0) ? 1 : (*sp)[*n-1].maSP + 1;
    NhapSanPham(&(*sp)[*n], newMaSP);
    (*n)++;
    printf(">>>Da them thanh cong! (Ma san pham: %d\n)", newMaSP);
}
void xoaSanPham(sanPham **sp, int *n){
    int maSP;
    printf("Nhap ma san pham can xoa: ");
    scanf("%d", &maSP);
    while(getchar() != '\n');
    int viTri = timKiemTheoMaSP(*sp, *n, maSP);
    if(viTri == -1){
        printf("Khong tim thay ma San Pham %d\n", maSP);
        return;
    }
    printf("\n=== SAN PHAM SE BI XOA ===\n");
    printf("%d | %s | %.2f | %d ", (*sp)[viTri].maSP, (*sp)[viTri].tenSP, (*sp)[viTri].gia, (*sp)[viTri].soLuong);
    printf("Xac Nhan (Y/N): ");
    char confirm = getchar();
    while(getchar() != '\n');
    if(confirm != 'y' && confirm != 'Y'){
        printf(">>> Huy xoa.\n");
        return;
    }
    //dịch các phần tử sau lên trước
    for(int i = viTri; i < *n-1;i++){
        (*sp)[i] = (*sp)[i+1];
    }
    (*n)--;
        //thu nhỏ bộ nhớ
    *sp = (sanPham*)realloc(*sp, (*n) * sizeof(sanPham));
    printf(">>> Da xoa thanh cong!\n");

}
void suaSanPham(sanPham sp[], int n){
    int id;
    printf("Nhap ma SP can sua: ");
    scanf("%d", &id);
    while(getchar() != '\n');
    int viTri = timKiemTheoMaSP(sp, n, id);
    if(viTri == -1){
        printf("Khong tim thay ma sp %d", id);
        return;
    }
    printf("\n=== THONG TIN HIEN TAI ===\n");
    printf("Ma SP: %d| ten SP: %s| gia: %.2f| so luong: %d", sp[viTri].maSP, sp[viTri].tenSP, sp[viTri].gia, sp[viTri].soLuong);

    printf("\n=== THONG TIN MOI ===\n");
    printf("Nhap ten moi: ");
    fgets(sp[viTri].tenSP, sizeof(sp[viTri].tenSP), stdin);
    sp[viTri].tenSP[strcspn(sp[viTri].tenSP, "\n")] = '\0';
    
    printf("Nhap gia: ");
    scanf("%f", &sp[viTri].gia);
    printf("so luong: ");
    scanf("%d", &sp[viTri].soLuong);
    while(getchar() != '\n');
    printf(">>>Da sua thanh cong!\n");
}
void hienThiSanPham(sanPham sp[], int n){
    if(n == 0){
        printf("Khong co san pham nao het!\n");
        return;
    }
    printf("\n%-10s %-30s %-15s %-10s\n", "MA SP", "Ten SP", "Gia", "So luong");
    for(int i = 0; i < n;i++){
        printf("%-10d %-30s %-15.2f %-10d\n", sp[i].maSP, sp[i].tenSP, sp[i].gia, sp[i].soLuong);
    }
}
void menu(){
    printf("\n========== MENU ==========\n");
    printf("1. Them san pham\n");
    printf("2. Xoa san pham\n");
    printf("3. Sua san pham\n");
    printf("4. Hien thi san pham\n");
    printf("5. Tao hoa don\n");
    printf("6. Tinh tong tien hoa don\n");
    printf("7. Thong ke doanh thu\n");
    printf("8. Kiem tra san pham sap het\n");
    printf("9. Luu file\n");
    printf("0. Thoat\n");
    printf("==========================\n");
    printf("Nhap lua chon: ");
}
void luuFileHoaDon(hoaDon hd[], int n){
    FILE *f = fopen("hoaDon.txt", "w");
    if(f == NULL){
        printf("Loi mo file");
        return;
    }
    fprintf(f, "%d\n", n);
    for(int i = 0; i < n;i++){
        fprintf(f,"%d|%d|%d|%.2f\n", hd[i].maHD, hd[i].maSP, hd[i].soLuongMua, hd[i].thanhTien);
    }
    fclose(f);
    printf(">>> Da luu file hoadon.txt\n");
}
int docFileHoaDon(hoaDon **hd){
    FILE *f = fopen("hoaDon.txt", "r");
    if(f == NULL){
        printf("Loi cap phat bo nho\n");
        fclose(f);
        return 0;
    }
    int n;
    fscanf(f, "%d\n", &n);
    *hd = (hoaDon*)malloc(n * sizeof(hoaDon));
    if(*hd == NULL){
        printf("Loi cap phat bo nho!\n");
        fclose(f);
        return 0;
    }
    for(int i = 0; i < n;i++){
        fscanf(f, "%d|%d|%d|%.2f", &(*hd)[i].maHD, &(*hd)[i].maSP, &(*hd)[i].soLuongMua, &(*hd)[i].thanhTien);
    }
    fclose(f);
    printf(">>>Da doc %d hoa don tu file\n", n);
    return n;
}
void taoHoaDon(hoaDon **hd, int *soHD, sanPham *sp, int soSP){
    int maSP, soLuongMua;
    printf("\n=== TAO HOA DON MOI ===\n");
    printf("Nhap ma san pham: ");
    scanf("%d", &maSP);
    while(getchar() != '\n');
    int viTri = timKiemTheoMaSP(sp, soSP, maSP);
    if(viTri == -1){
        printf("khong tim thay san pham co ma %d\n", maSP);
        return;
    }
    printf("San pham: %s | Gia: %.2f | Ton kho: %d\n", sp[viTri].tenSP, sp[viTri].gia, sp[viTri].soLuong);
    printf("Nhap so luong  mua: ");
    scanf("%d", &soLuongMua);
    while(getchar() != '\n');
    if(soLuongMua > sp[viTri].soLuong){
        printf("khong du so luong! chi con %d san pham\n", sp[viTri].soLuong);
        return;
    }
    if(soLuongMua <= 0){
        printf("So luong khong hop le\n");
        return;
    }
    *hd = (hoaDon*)realloc(*hd, (*soHD+1)*sizeof(hoaDon));
    if(*hd == NULL){
        printf("Loi cap phat bo nho!\n");
        return;
    }
    int maHD = (*soHD == 0) ? 1: (*hd)[*soHD-1].maHD +1;
    (*hd)[*soHD].maHD = maHD;
    (*hd)[*soHD].maSP = maSP;
    (*hd)[*soHD].soLuongMua = soLuongMua;
    (*hd)[*soHD].thanhTien = soLuongMua * sp[viTri].gia;

    sp[viTri].soLuong -= soLuongMua;
    (*soHD)++;
    printf(">>>Tao hoa don thanh cong!\n");
    printf("Ma hoa don: %d\n", maHD);
    printf("Thanh tien : %.2f\n", (*hd)[*soHD-1].thanhTien);
}
void tinhTongTienHoaDon(hoaDon hd[], int soHD){
    if(soHD == 0){
        printf("chua co hoa don nao!\n");
        return;
    }    
    int maHD;
    printf("Nhap ma hoa don can tinh: ");
    scanf("%d", &maHD);
    while(getchar() != '\n');
    float tongTien = 0;
    int found = 0;

    printf("\n=== CHI TIET HOA DON%d ===\n", maHD);
    printf("%-10s %-10s %-15s\n", "MA SP", "SO LUONG", "THANH TIEN");
    for(int i = 0; i < soHD;i++){
        if(hd[i].maHD == maHD){
            printf("%-10d %-10d %-15.2f\n", hd[i].maSP, hd[i].soLuongMua, hd[i].thanhTien);
            tongTien += hd[i].thanhTien;
            found = 1;
        }
    }
    if(!found){
        printf("Khong tim thay ma hoa don %d\n", maHD);
        return;
    }
    printf("Tong tien: %.2f\n", tongTien);
}
void thongKeDoanhThu(hoaDon hd[], int soHD){
    if(soHD == 0){
        printf("khong tim thay hoa don nao!\n");
        return;
    }
    float tongDoanhThu = 0;
    for(int i = 0; i < soHD;i++){
        tongDoanhThu += hd[i].thanhTien;
    }
    printf("\n=== TONG DOANH THU ===\n");
    printf("Tong so hoa don: %d\n", soHD);
    printf("Tong doanh thu: %.2f\n", tongDoanhThu);
    printf("Doanh thu trung binh/hoa don: %.2f\n", tongDoanhThu/soHD);
}
void kiemTraSoLuong(sanPham sp[], int n){
    printf("\n=== SAN PHAM SAP HET ===\n");
    printf("%-10s %-30s %-10s\n", "MA SP", "Ten SP", "So luong");
    int count = 0;
    for(int i = 0; i < n;i++){
        if(sp[i].soLuong < 10){
            printf("%-10d %-30s %-10d\n", sp[i].maSP, sp[i].tenSP, sp[i].soLuong);
            count++;
        }  
    }
    if(count == 0){
        printf("Tat ca san pham deu con du!\n");
    }
}
int main(){
    sanPham *sp = NULL;
    hoaDon *hd = NULL;
    int soSP = 0;
    int soHD = 0;
    int luaChon;
    soSP = docFileSanPham(&sp);
    soHD = docFileHoaDon(&hd); 

    do{ 
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');

        switch(luaChon){
            case 1: 
                themSanPham(&sp, &soSP);
                break;
            case 2:
                xoaSanPham(&sp, &soSP);
                break;
            case 3:
                suaSanPham(sp, soSP);
                break;
            case 4:
                hienThiSanPham(sp, soSP);
                break;
            case 5: 
                taoHoaDon(&hd, &soHD, sp, soSP);
                break;
            case 6:
                tinhTongTienHoaDon(hd, soHD);
                break;
            case 7:
                thongKeDoanhThu(hd, soHD);
                break;
            case 8: 
                kiemTraSoLuong(sp, soSP);
                break;
            case 9: 
                luuFileSanPham(sp, soSP);
                luuFileHoaDon(hd, soHD);
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }while(luaChon != 0);
    free(sp);
    free(hd);
    return 0;
}