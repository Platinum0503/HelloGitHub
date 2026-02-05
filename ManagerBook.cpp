#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sach {
    int id;
    char tenSach[50];
    char tenTacGia[50];
    int namXuatBan;
} sach;
void luuFile(sach s[], int n){
    FILE *f = fopen("sach.txt", "w");
    if(f == NULL){
        printf("Loi mo file!");
        return;
    }
    fprintf(f, "%d\n", n);
    for(int i = 0;i < n;i++){
        fprintf(f, "%d|%s|%s|%d", s[i].id, s[i].tenSach, s[i].tenTacGia, s[i].namXuatBan);
    }
    fclose(f);
    printf(">>> Da luu file!\n");
}
int docFile(sach **s){
    FILE *f = fopen("sach.txt", "r");
    if(f == NULL){
        printf("Loi! khong tim thay file! khoi tao file moi\n");
        return 0;
    }
    int n;
    fscanf(f, "%d\n", &n);
    *s = (sach*)malloc(n * sizeof(sach)); //cấp phát bộ nhớ
    if(*s == NULL){
        printf("Loi cap phat bo nho!\n");
        fclose(f);
        return 0;
    }
    for(int i = 0; i < n;i++){
        fscanf(f, "%d|%s|%s|%d", &(*s)[i].id, (*s)[i].tenSach, (*s)[i].tenTacGia, &(*s)[i].namXuatBan);
    }
    fclose(f);
    printf(">>> Da doc %d phan tu trong file", n);
    return n;
}
void inputBook(sach *s, int id){
    s->id = id;
    int n;
    printf("Nhap n cuon sach: ");
    scanf("%d", &n);
   // s = (sach)malloc(n * sizeof(sach));
    while(getchar() != '\n');
    if(n == 0){
        printf("Loi! danh sach rong");
        return;
    }
    printf("Nhap ten sach: ");
    fgets(s->tenSach, sizeof(s->tenSach), stdin);
    s->tenSach[strcspn(s->tenSach, "\n")] = '\0';
    printf("Nhap ten tac gia: ");
    fgets(s->tenTacGia, sizeof(s->tenTacGia), stdin);
    s->tenTacGia[strcspn(s->tenTacGia, "\n")] = '\0';
    printf("Nhap nam san xuat: ");
    scanf("%d", &s->namXuatBan);
    while(getchar() != '\n');
}
void output(sach s){
    printf("\n=== THONG TIN SACH ===\n");
    printf("ID: %d\n", s.id);
    printf("Ten sach: %s\n", s.tenSach);
    printf("Ten tac gia: %s\n", s.tenTacGia);
    printf("Nam xuat ban: %d\n", s.namXuatBan);
}
void searchTen(sach s[], int n){
    char ten[50];
    printf("Nhap ten tac gia: ");
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0';
    int found = 0;
    printf("\n=== KET QUA TIM KIEM ===\n");
    for(int i = 0;i < n;i++){
        if(strstr(s[i].tenTacGia, ten) != NULL){
            printf("ID: %d |Ten Sach: %s| Ten tac gia: %s|Nam xuat ban: %d", s[i].id, s[i].tenSach, s[i].tenTacGia, s[i].namXuatBan);
            found = 1;
        }
    }
    if(!found){
        printf("Khong tim thay ten tac gia: %s", ten);
    }
}
void menu(){
    printf("\n=== MENU ===\n");
    printf("1.Nhap n cuon sach\n");
    printf("2.In danh sach\n");
    printf("3.search sach theo ten tac gia\n");
    printf("4.Luu vao file\n");
    printf("5.Doc file\n");
    printf("0.Thoat\n");
    printf("Nhap lua chon: ");
}
int main(){
    sach *s = NULL;
    int n = 0;
    int luaChon;
    n = docFile(&s);
    do {
        menu();
        scanf("%d", &luaChon);
        while(getchar() != '\n');
        switch(luaChon){
            case 1:
                s = (sach*)realloc(s, (n+1) * sizeof(sach));
                if(s == NULL){
                    printf("Loi cap phat bo nho!");
                    break;
                }
                inputBook(&s[n], n+1);
                n++;
                printf(">>>Da them sach thanh cong\n");
                break;
            case 2: 
                output(*s);
                break;
            case 3: 
                searchTen(s, n);
                break;
            case 4:
                luuFile(s, n);
                break;
            case 5:
                free(s);
                s = NULL;
                n = docFile(&s); //read từ đầu file
                break;
            case 0: 
                printf("Dang thoat. Tam biet!\n");
                break;
            default:
                printf("Loi! nhap khong hop le, nhap lai: ");
        }
        
    }while(luaChon != 0);
    free(s);
    return 0;
}