#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct sanPham{
    int id;
    char ten[50];
    float gia;
};

void luuFile(sanPham sp[], int n){
    FILE *f = fopen ("sanpham.txt", "w");
    if(f == NULL){
        printf("loi mo file!\n");
        return;
    }
    fprintf(f, "%d\n", n);
    for(int i = 0; i < n;i++){
        fprintf(f, "%d|%s|%.2f", sp[i].id, sp[i].ten, sp[i].gia);
    }
    fclose(f);
    printf(">>> Da luu file!\n");
}

int docFile(sanPham **sp){
    FILE *f = fopen("sanpham.txt", "r");
    if(f == NULL){
        printf("khong tim thay danh sach! bat dau danh sach moi!\n");
        return 0;
    }
    int n;
    fscanf(f, "%d", &n);
    *sp = (sanPham*)malloc(n * sizeof(sanPham));
    if(*sp == NULL){
        printf("Loi cap phat!\n");
        fclose(f);
        return 0;
    }

    for(int i = 0;i < n;i++){
        fscanf(f, "%d|%s|%.2f", &(*sp)[i].id, &(*sp)[i].ten, &(*sp)[i].gia);
    }
    fclose(f);
    printf(">>>Da doc %d san pham tu file\n", n);
    return n;
}

void nhapSanPham(sanPham *sp, int id){
    sp->id = id;
    printf("Nhap ten: ");
    fgets(sp->ten, sizeof(sp->ten), stdin);
    sp->ten[strcspn(sp->ten, "\n")] = '\0';
    printf("Nhap gia: ");
    scanf("%f", &sp->gia);
    while(getchar() != '\n');
}

void giaCaoNhat(sanPham sp[], int n){
    if(n == 0){
        printf("Khong co san pham nao!\n");
        return;
    }
    int viTri = 0;
    float max = sp[0].gia;
    for(int i = 1;i < n;i++){
        if(sp[i].gia > max){
            max = sp[i].gia;
            viTri = i;
        }
    }
    printf("\n=== SAN PHAM CO GIA CAO NHAT ===\n");
    printf("%d|%s|%.2f", sp[viTri].id, sp[viTri].ten, sp[viTri].gia);
}
void input(sanPham sp[], int n){
    printf("\n=== DANH SACH SAN PHAM ===\n");
    if(n == 0){
        printf("Danh sach rong!\n");
        return;
    }

    for(int i = 0;i < n;i++){
        printf("%d|%s|%.2f", sp[i].id, sp[i].ten, sp[i].gia);
    }
}

void menu(){
    printf("\n=== MENU ===\n");
    printf("1.Nhap san pham\n");
    printf("2.Xem danh sach san pham\n");
    printf("3.Luu file\n");
    printf("4.Xem file\n");
    printf("0.Thoat\n");
    printf("Nhap lua chon cua ban: ");
}
int main(){
    sanPham *sp = NULL;
    int n = 0;
    int luaChon;

    n = docFile(&sp);

    do {
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');

        switch(luaChon){
            case 1:
                sp = (sanPham*)realloc(sp, (n + 1) * sizeof(sanPham));
                if(sp == NULL){
                    printf("Loi cap phat bo nho!\n");
                    break;
                }
                nhapSanPham(&sp[n], n+1);
                n++;
                break;
            case 2:
                input(sp, n);
                break;
            case 3:
                luuFile(sp, n);
                break;
            case 4:
                giaCaoNhat(sp, n);
                break;
            case 0:
                printf("\nDang Thaot. Tam Biet!");
                break;
            default: 
                printf("Nhap khong hop le! nhap lai: ");
        }

    }while(luaChon != 0);
    free(sp);
    return 0;
}
