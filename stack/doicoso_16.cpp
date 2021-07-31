
#include <stdio.h>
#include <string.h>

#define MAX_SIZE    100

typedef struct{
    char c;
} STACK;

STACK stack[MAX_SIZE];
int top;

int isFull(){
    if(top == MAX_SIZE){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

void push(int du){
    if(!isFull()){
        top++;
        
        if(du>=0&&du<=9){
            stack[top].c = du + '0';
        }else if(du>=10 && du<=15){
            switch (du) {
                case 10:
                    stack[top].c = 'A';
                    break;
                case 11:
                    stack[top].c = 'B';
                    break;
                case 12:
                    stack[top].c = 'C';
                    break;
                case 13:
                    stack[top].c = 'D';
                    break;
                case 14:
                    stack[top].c = 'E';
                    break;
                case 15:
                    stack[top].c = 'F';
                    break;
            }
        }
    }else{
        printf("Stack da day, khong the them phan tu\n");
    }
}

char pop(){
    if(!isEmpty()){
        char c = stack[top].c;
        top--;
        return c;
    }else{
        return -1;
    }
}

void doiCoSo(int n){
    int du;
    while(n!=0){
        du = n% 16;
        n = n/16;
        push(du);
    }
}

void hienThiKQ(){
    for(int i=top;i>=0;i--){
        printf("%c", stack[i].c);
    }
    printf("\n");
}



/**
 Câu 13:  Viết chương trình đổi một số thập phân n>=0 nhập vào từ bàn phím sang các cơ số 2, 8, 16 bằng cách dùng cấu trúc dữ liệu STACK. Chương trình được tổ chức thành các chương trình con sau:
1)Hàm push(): đẩy một phần tử vào ngăn xếp
2)Hàm pop(): loại bỏ 1 phần tử khỏi ngăn xếp
3)Hàm chuyen co so(): đổi một số thập phân n>=0 sang hệ cơ số bất kì
4)Hàm hienketqua(): hiển thị kết quả ra màn hình
Hàm main() hiển thị menu để chọn các chức năng bằng cách nhập số tương ứng như sau
1.Chuyen mot so nguyen dương sang he 2
2.Chuyen mot so nguyen dương sang he 8
3.Chuyen mot so nguyen dương sang he 16
4.Ket thuc
 */

int main(){
    top = -1;
    
    int n = 123;
    
    doiCoSo(n);
    hienThiKQ();
    
    return 0;
}
