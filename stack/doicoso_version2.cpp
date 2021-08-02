#include <stdio.h>
#include <string.h>

#define MAX_SIZE    100

typedef struct{
    int data;
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
            stack[top].data = du;
        }else if(du>=10 && du<=15){
            // A, B, C, D, E, F
            // 10 -> A (65)
            // 11 -> B (66)
            // 12 -> C (67)
            // 13 -> D (68)
            // 14 -> E (69)
            // 15 -> F (70)
            
            // => du + 55 -> ky tu {A, B, C, D, E, F}
            stack[top].data = du+55;
        }
    }else{
        printf("Stack da day, khong the them phan tu\n");
    }
}

int pop(){
    if(!isEmpty()){
        int ret = stack[top].data;
        top--;
        return ret;
    }else{
        printf("Stack rong, khong the lay phan tu\n");
        return -1;
    }
}

void doiCoSo(int n, int heCoSo){
    int du;
    while(n!=0){
        du = n% heCoSo;
        n = n/heCoSo;
        push(du);
    }
}

void hienThiKQ(){
    while(!isEmpty()){
        int data = pop();
        if(0<=data && data<=9){
            printf("%d", data);
        }else if('A'<=data && data <= 'F'){
            printf("%c", data);
        }
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
    
    doiCoSo(n, 16);
    hienThiKQ();
    
    return 0;
}
