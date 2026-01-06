#include <stdio.h>
#include <string.h>

int main(){
    char cau[1000];
    printf("Nhap cau: ");
    fgets(cau, sizeof(cau), stdin);

    int len = strlen(cau); // Lấy độ dài chuỗi
    if(cau[len - 1] == '\n'){ // Kiểm tra ký tự cuối có phải \n không
        cau[len - 1] = '\0';     // Thay \n bằng \0
        len--;            // Giảm độ dài
    }

    printf("cau dao nguoc: ");
    int end = len - 1;  // Vị trí cuối từ hiện tại
    for(int i = len - 1; i >= -1;i--){
        if(i == -1 || cau[i] == ' '){
            // In từ từ vị trí i+1 đến end
            for(int j = i+1;j <= end;j++){
                printf("%c", cau[j]);
            }

            if(i >= 0){
                printf(" ");    // Không in space ở từ đầu tiên
            }
            end = i -1;
        }
    }
    printf("\n");
    return 0;
}