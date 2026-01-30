    return n;
}
void input(sach *s, int id){
    s->id = id;
    int n;
    printf("Nhap n cuon sach muon nhap: ");
    scanf("%d", &n);
    while(getchar() != '\n');
    if(n == 0){
        printf("Loi! n khong hop le");
        return;
    }
    printf("Nhap ten sach: ");
    fgets(s->ten, sizeof(s->ten), stdin);
    s->ten[strcspn(s->ten, "\n")] = '\0';
    printf("Nhap ten sach gia: ");
    fgets(s->tenTacGia, sizeof(s->tenTacGia), stdin);
    s->tenTacGia[strcspn(s->tenTacGia, "\n")] = '\0';
    printf("Nam xuat ban: ");
    scanf("%d", &s->namXuatBan);
    while(getchar() != '\n');
}
void output(sach s){
    printf("\n=== THONG TIN SACH ===\n");
    printf("ID: %d", s.id);
    printf("Ten sach: %s", s.ten);
    printf("Tac Gia: %s", s.tenTacGia);
    printf("Nam xuat ban: %d", s.namXuatBan);
}
void search(sach s[], int n){
    char ten[50];
    printf("Nhap ten tac gia: ");
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0';
    int found = 0;
    printf("\n=== KET QUA TIM KIEM ===\n");
    for(int i = 0; i < n;i++){
        if(strstr(s[i].tenTacGia, ten) != NULL){
            printf("ID: %d | Ten sach: %s | Ten tac gia: %s | Nam xuat ban: %d", s[i].id, s[i].ten, s[i].tenTacGia, s[i].namXuatBan);
            found = 1;
        }
    }
    if(!found){
        printf("Khong tim thay ten tac gia %s", ten);
    }
}
void menu(){
    printf("\n=== MENU ===\n");
    printf("1.Nhap sach\n");
    printf("2.Xem danh sach\n");
    printf("3.Tim kiem theo ten tac gia\n");
    printf("4.luu file\n");
    printf("5.Xem file\n");
    printf("0.Thoat\n");
    printf("Nhap lua chon cua ban: ");
}
int main(){
    sach *s = NULL;
    int n = 0;
    int luaChon;
    n = docFile(&s);

    do {
        menu();
        scanf("%d", &luaChon);