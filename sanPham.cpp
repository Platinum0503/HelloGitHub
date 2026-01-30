#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sanPham{
    int id;
    char ten[50];
    float gia;
};

void luuFile(sanPham sp[], int n){
    FILE *f = fopen ("sanPham1.txt", "w");
    if(f == NULL){
        printf("Loi mo file\n");
        return;
    }

    fprintf(f, "%d\n", n);
    for(int i = 0; i < n;i++){
        fprintf(f, "%d|%s|%f", sp[i].id, sp[i].ten, sp[i].gia);
    }
    fclose(f);
    printf(">>> Da luu file!\n");
}

int docFile(sanPham **sp){
    FILE *f = fopen("sanPham1.txt", "r");
    if(f == NULL){
        printf("Loi! khong tim thay file! khoi tao file moi\n");
        return 0;
    }
    int n;
    fscanf(f, "%d\n", n);
    *sp = (sanPham*)malloc(n * sizeof(sanPham));
    if(*sp == NULL){
        printf("Loi cap phat!");
        fclose(f);
        return 0;
    }
    for(int i = 0;i < n;i++){
        fscanf(f, "%d|%s|%.2f", (*sp)[i].id, (*sp)[i].ten, (*sp)[i].gia);
    }
    fclose(f);
    printf("Da doc %d san pham tu file", n);
    return n;
}
void nhapSanPham(sanPham *sp, int id){
    sp->id = id;
    printf("Nhap ten san pham: ");
    fgets(sp->ten, sizeof(sp->ten), stdin);
    sp->ten[strcspn(sp->ten, "\n")] = '\0';
    printf("Nhap gia san pham: ");
    scanf("%f", &sp->gia);
    while(getchar() != '\n');
}
void giaCaoNhat(sanPham sp[], int n){
    if(n == 0){
        printf("Rong! khong co san pham nao het\n");
        return;
    }
    int viTri = 0;
    int max = sp[viTri].gia;
    for(int i = 0; i < n;i++){
        if(sp[i].gia > max){
            max = sp[i].gia;
            viTri = i;
        }
    }
    printf("\n=== SAN PHAM CO GIA CAO NHAT ===\n");
    printf("%d|%s|%.2f", sp[viTri].id, sp[viTri].ten, sp[viTri].gia);
}
void input(sanPham sp[], int n){
    if(n == 0){
        printf("Rong! khong co san pham nao het\n");
        return;
    }
    printf("\n=== SAN PHAM ===\n");
    for(int i =0; i < n;i++){
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
    do {
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');
        switch(luaChon){
            case 1:
                sp = (sanPham*)realloc(sp, (n+1) * sizeof(sanPham));
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
                printf("Dang Thoat. Tam Biet!\n");
                break;
            default: 
                printf("Nhap khong hop le! Nhap lai: ");
        }
    }while(luaChon != 0);
    free(sp);
    return 0;
}