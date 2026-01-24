    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    typedef struct sach{
        int maSach;
        char tenSach[50];
        char tacGia[50];
        int namXB;
        int soLuong;
    } sach;

    typedef struct phieuMuon{
        int maPhieu;
        int maSach;
        char tenNguoiMuon[50];
        char ngayMuon[20];
    } phieuMuon;

    void luuFileSach(sach s[], int n){
        FILE *f = fopen("sach.txt", "w");
        if(f == NULL){
            printf("Loi mo file! tao file moi");
            return;
        }
        fprintf(f, "%d\n", n);
        for(int i = 0; i < n;i++){
            fprintf(f, "%d|%s|%s|%d|%d\n", s[i].maSach, s[i].tenSach, s[i].tacGia, s[i].namXB, s[i].soLuong);
        } //thêm \n ở format
        fclose(f);
        printf(">>>Da luu file thanh cong!");
    }
    int docFileSach(sach **s){
        FILE *f = fopen("sach.txt", "r");
        if(f == NULL){
            printf("Loi cap phat bo nho");
            return 0;
        }
        int n;
        fscanf(f, "%d\n", &n);
        *s = (sach*)malloc(n * sizeof(sach));
        for(int i = 0; i < n;i++){
            fscanf(f, "%d|[^|]|[^|]|%d|%d", &(*s)[i].maSach, (*s)[i].tenSach, &(*s)[i].tacGia, &(*s)[i].namXB, &(*s)[i].soLuong);
        } //chú ý, cần &
        fclose(f);
        printf(">>>Da doc %d sach trong file", n);
        return n;
    }
    void nhapSach(sach *s, int maSach){
        s->maSach = maSach;
        printf("Nhap ten sach: ");
        fgets(s->tenSach, sizeof(s->tenSach), stdin);
        s->tenSach[strcspn(s->tenSach, "\n")] = '\0';

        printf("Ten tac gia: ");
        fgets(s->tacGia, sizeof(s->tacGia), stdin);
        s->tacGia[strcspn(s->tacGia, "\n")] = '\0';

        printf("Nam xuat ban: ");
        scanf("%d",&(s->namXB));
        while(getchar() != '\n');

        printf("Nhap so luong sach: ");
        scanf("%d", &(s->soLuong));
        while(getchar() != '\n');
        printf(">>>Nhap thanh cong sach vao thu vien!\n");
    }
    void hienThiSach(sach s[], int n){
        if(n == 0){
            printf("Danh sach rong!");
            return;
        }
        for(int i = 0; i < n;i++){
            printf("%d|%s|%s|%d|%d\n", s[i].maSach, s[i].tenSach, s[i].tacGia, s[i].namXB, s[i].soLuong);
        }
    }
    int timKiemMaSach(sach s[], int n, int maSach){
        for(int i = 0; i < n;i++){
            if(s[i].maSach == maSach){
                return i;
            }
        }
        return -1;
    }
    void themSach(sach **s, int *n){
        *s = (sach*)realloc(*s, (*n+1)*sizeof(sach));
        if(*s == NULL){
            printf("Loi cap phat bo nho!\n");
            return;
        }
        printf("\n=== THEM SACH MOI ===\n");
        int newMaSach = (*n == 0) ? 1 : (*s)[*n-1].maSach + 1;
        nhapSach(&(*s)[*n], newMaSach); //caution
        (*n)++;
        printf(">>>Da them sach vao thu vien thanh cong!(Ma sach: %d)\n", newMaSach);
    }
    void xoaSach(sach **s, int *n){
        if(*n == 0){
            printf("Danh sach rong!");
            return;
        }
        int maSach;
        printf("Nhap ma sach: ");
        scanf("%d", &maSach);
        while(getchar() != '\n');
        int viTri = timKiemMaSach(*s, *n, maSach);
        if(viTri == -1){
            printf("Khong tim thay sach co ma %d", maSach);
            return;
        }
        printf("\n=== THONG TIN SACH HIEN TAI ===\n");
        printf("%d|%s|%s|%d|%d", (*s)[viTri].maSach, (*s)[viTri].tenSach, (*s)[viTri].tacGia, (*s)[viTri].namXB, (*s)[viTri].soLuong);
        printf("Xac nhan (y/n): ");
        char confirm = getchar();
        while(getchar() != '\n');
        if(confirm != 'y' && confirm != 'Y'){
            printf("Huy xoa!\n");
            return;
        }
        for(int i = viTri; i < *n-1;i++){
            (*s)[i] = (*s)[i+1];
        }
        (*n)--; //caution
        printf(">>>Da xoa thanh cong sach co ma %d", maSach);
    }
    void suaSach(sach s[], int n){
        int maSach;
        printf("Nhap ma sach: ");
        scanf("%d", &maSach);
        while(getchar() != '\n');

        int viTri = timKiemMaSach(s, n, maSach);
        if(viTri == -1){
            printf("Khong tim thay sach nay!");
            return;
        }
        printf("\n=== THONG TIN SACH HIEN TAI ===\n");
        printf("%d|%s|%s|%d|%d", s[viTri].maSach, s[viTri].tenSach, s[viTri].tacGia, s[viTri].namXB, s[viTri].soLuong);
        printf("Xac nhan (y/n): "); //in xac nhan truoc
        char confirm = getchar();   //này là đọc ở dòng trên (y/n)
        while(getchar() != '\n');
        if(confirm != 'y' && confirm != 'Y'){
            printf("Huy!");
            return;
        }
        printf("\n=== THONG TIN MOI ===\n");
        printf("Nhap ten sach: ");
        fgets(s[viTri].tenSach, sizeof(s[viTri].tenSach), stdin);
        s[viTri].tenSach[strcspn(s[viTri].tenSach, "\n")] = '\0';

        printf("Nhap ten tac gia: ");
        fgets(s[viTri].tacGia, sizeof(s[viTri].tacGia), stdin);
        s[viTri].tacGia[strcspn(s[viTri].tacGia, "\n")] = '\0';

        printf("Nhap nam xuat ban: ");
        scanf("%d", &s[viTri].namXB);
        while(getchar() != '\n');

        printf("Nhap so luong: ");
        scanf("%d", &s[viTri].soLuong);
        while(getchar() != '\n');
        
        printf(">>>Thay doi thong tin thanh cong (ma sach: %d)", maSach);
    }       
    void luuFilePhieu(phieuMuon p[], int n){
        FILE *f = fopen("phieuMuon.txt", "w");
        if(f == NULL){
            printf("Loi cap phat bo nho!\n");
            return;
        }
        fprintf(f,"%d\n", n); //cần \n
        for(int i = 0; i < n;i++){
            fprintf(f, "%d|%d|%s|%s\n", p[i].maPhieu, p[i].maSach, p[i].tenNguoiMuon, p[i].ngayMuon);
        } //cần \n trong format
        fclose(f);
        printf(">>>Da doc File thanh cong");
    }
    int docFilePhieu(phieuMuon **p){
        FILE *f = fopen("phieuMuon.txt","r");
        if(f == NULL){
            printf("Loi mo file!");
            return 0;
        }
        int n;
        fscanf(f, "%d\n", &n); //cần malloc ở đọc file
        *p = (phieuMuon*)malloc(n * sizeof(phieuMuon));
        for(int i = 0; i < n;i++){
            fscanf(f, "%d|%d|%[^|]|%[^|]|%s\n", &(*p)[i].maPhieu, &(*p)[i].maSach, (*p)[i].tenNguoiMuon, (*p)[i].ngayMuon);
        }
        fclose(f);
        printf(">>>Doc File thanh cong!");
        return n;
    }
    void taoPhieuMuon(phieuMuon **pm, int *soPhieuMuon, sach *s, int soSach){
        int maSach, soLuong;
        char tenNguoiMuon[50];
        char ngayMuon[20];
        //không nhâp tên người mượn và ngày mượn trước khi nhập mã sách
        // scanf sẽ bỏ qua \n còn lại từ fgets
        printf("\n=== PHIEU MUON SACH ===\n");
        printf("Nhap ma sach: ");
        scanf("%d", &maSach);
        while(getchar() != '\n');
        int viTri = timKiemMaSach(s, soSach, maSach); //caution
        if(viTri == -1){
            printf("Khong tim thay sach co ma %d", maSach);
            return;
        }
        printf("Nhap ten nguoi muon: ");
        fgets(tenNguoiMuon, sizeof(tenNguoiMuon), stdin);
        tenNguoiMuon[strcspn(tenNguoiMuon, "\n")] = '\0';

        printf("Nhap ngay muon: ");
        fgets(ngayMuon, sizeof(ngayMuon), stdin);
        ngayMuon[strcspn(ngayMuon, "\n")]= '\0';

        printf("Ten sach: %s | Tac gia: %s | Nam xuat ban: %d | so luong: %d", s[viTri].tenSach, s[viTri].tacGia, s[viTri].namXB, s[viTri].soLuong);
        printf("Nhap so luong muon muon: ");
        scanf("%d", &soLuong);
        while(getchar() != '\n');
        if(soLuong > s[viTri].soLuong){
            printf("so luong sach trong thu vien khong du! chi con (%d)", s[viTri].soLuong);
            return;
        }
        if(soLuong <= 0){
            printf("So luong khong hop le!");
            return;
        }
        *pm = (phieuMuon*)realloc(*pm, (*soPhieuMuon+1)*sizeof(phieuMuon));
        if(*pm == NULL){
            printf("Loi cap phat bo nho!");
            return;
        }
        int maPhieu = (*soPhieuMuon == 0) ? 1 : (*pm)[*soPhieuMuon-1].maPhieu+1;
        (*pm)[*soPhieuMuon].maPhieu = maPhieu;
        (*pm)[*soPhieuMuon].maSach = maSach;
        strcpy((*pm)[*soPhieuMuon].tenNguoiMuon, tenNguoiMuon);
        strcpy((*pm)[*soPhieuMuon].ngayMuon, ngayMuon);
        //strcpy là copy 

        s[viTri].soLuong -= soLuong;
        (*soPhieuMuon)++;
        printf(">>>Tao thanh cong phieu muon\n");
        printf("Nguoi muon: %s", tenNguoiMuon);
        printf("\nNgay muon: %s", ngayMuon);
    }
    void sachSapHet(sach s[], int n){
        if(n == 0){
            printf("Danh sach Rong!\n");
            return;
        }
        printf("\n=== SACH SAP HET ===\n");
        printf("%-10s %-30s %-30s %-15s %-10s\n", "Ma sach", "Ten sach", "Tac gia", "Nam xuat ban", "So luong");
        // chú ý cần \n trong format
        int count = 0;
        for(int i = 0; i < n;i++){
            if(s[i].soLuong < 10){
                printf("%-10d %-10s %-30s %-10d %-30d", s[i].maSach, s[i].tenSach, s[i].tacGia, s[i].namXB, s[i].soLuong);
                count++;
            }
        }
        if(count == 0){
            printf("Tat ca sach deu con du!");
            return;
        }
    }
    void tinhSoSachDaMuon(phieuMuon *pm, int soPhieu, sach *s, int soSach){
        if(soPhieu == 0){
            printf("Chua co phieu muon nao!\n");
            return;
        }
        printf("\n=== THONG KE SACH DA MUON ===\n");
        printf("%-10s %-30s %-20s\n", "Ma sach", "Ten sach", "So luong muon: ");
        for(int i = 0; i < soSach;i++){
            int demMuon = 0;
            for(int j = 0;j < soPhieu;j++){
                if(pm[j].maSach == s[i].maSach){
                    demMuon++;
                }
            }
            if(demMuon > 0){
                printf("%-10d %-30s %-20d\n", s[i].maSach, s[i].tenSach, demMuon);
            }
        }
    }
    void menu(){
        printf("\n=== MENU ===\n");
        printf("1.Them sach\n");
        printf("2.Xoa sach\n");
        printf("3.Sua sach\n");
        printf("4.Hien thi sach\n");
        printf("5.Tao phieu muon sach\n");
        printf("6.Tinh so sach da muon\n");
        printf("7.Thong ke sach sap het!\n");
        printf("0.Thoat\n");
        printf("Nhap lua chon: ");
    }
    int main(){
        sach *s = NULL;
        phieuMuon *pm = NULL;
        int soLuong = 0;
        int soPM = 0;
        int luaChon;

        do{
            menu();
            scanf("%d", &luaChon);
            while(getchar() != '\n');

            switch(luaChon){
                case 1:
                    themSach(&s, &soLuong);
                    break;
                case 2: 
                    xoaSach(&s, &soLuong);
                    break;
                case 3:     
                    suaSach(s, soLuong);
                    break;
                case 4: 
                    hienThiSach(s, soLuong);
                    break;
                case 5: 
                    taoPhieuMuon(&pm, &soPM, s, soLuong);
                    break;
                case 6: 
                    tinhSoSachDaMuon(pm, soPM, s, soLuong);
                    break;
                case 7:
                    sachSapHet(s, soLuong);
                    break;
                case 0:
                    printf("Dang Thoat...Tam Biet!");
                    break;
                default:
                    printf("Lua chon khong hop le! Nhap lai: ");
            }
        }while(luaChon != 0);
        free(s);
        free(pm);
        return 0;
    }