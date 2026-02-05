#include <stdio.h>
#include <stdlib.h>

struct number {
    float so[5];
} nunmber;

void luuFile(number s[], int n){
    FILE *f = fopen("number.txt", "w"); // "w" = Write mode (Chế độ GHI)
    if(f == NULL){
        printf("Loi mo file\n");
        return;
    }
    fprintf(f, "%d\n", n);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < 5;j++){
        fprintf(f, "%f", s[i].so[j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    printf(">>> Da luu file!\n");
}

int docFile(number **s){
    FILE *f = fopen("number.txt", "r"); //"r"Read (Đọc)Mở file để ĐỌC. File phải tồn tại.
    if(f == NULL){
        printf(">>> khong tim thay file! bat dau danh sach moi.\n");
        return 0; //caution
    }

    int n;
    fscanf(f, "%d", &n);

    *s = (number*)malloc(n * sizeof(number)); //malloc cap phat bo nho (tuỳ thuộc input n của người dùng)
    if(*s == NULL){
        printf("Loi cap phat!\n");
        fclose(f);
        return 0;
    }

    for(int i = 0; i < n;i++){
        for(int j = 0; j < 5;j++){
        fscanf(f, "%f", &(*s)[i].so[j]); //caution
        }
    }
    fclose(f);
    printf(">>> Da doc %d number tu File.\n", n);
    return n;
}

void inFile(number s[], int n){
    if(n == 0){
        printf("\n=== Danh sach rong! ===\n");
        return;
    }

    printf("\n=== In File ===\n");
    for(int i = 0; i < n;i++){
        printf("Number %d: ", i+1);
        for(int j = 0; j < 5;j++){
        printf("%.2f ", s[i].so[j]);
        }
        printf("\n");
    }
}

void menu(){
    printf("\n=== MENU ===\n");
    printf("1. Nhap 5 number vao mang!\n");
    printf("2. Luu vao File\n");
    printf("3. Doc File\n");
    printf("4. Input File\n");
    printf("0. Thoat\n");
    printf("Nhap lua chon cua ban: ");
}

void nhapNumber(number **s, int *n){
    *n = 1;
    *s = (number*)malloc(sizeof(number));
    for(int i = 0; i < 5;i++){
        printf("Nhap so thu%d ",i+1);
        scanf("%f", &(*s)[0].so[i]);
    }
    printf(">>> Nhap thanh cong!\n");
}

int main(){
    number *danhSach = NULL;
    int n = 0;
    int luaChon;

    n = docFile(&danhSach);

    do{
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');
        switch(luaChon){
            case 1:
                nhapNumber(&danhSach, &n);
                break;
            case 2: 
                luuFile(danhSach, n);
                break;
            case 3: //error
                inFile(danhSach, n);
                break;
            case 4: //error
                inFile(danhSach, n);
                break;
            case 0:
                luuFile(danhSach, n);
                printf("\n>> Thoat. Tam Biet!\n");
                break;
            default: 
                printf("\nLua chon khong hop le! Vui long chon lai!\n");
        }
        
    }while(luaChon != 0);

    free(danhSach);

    return 0;
}