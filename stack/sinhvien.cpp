
#include <stdio.h>
#include <string.h>

#define MAX_SIZE    100

typedef struct{
    int maSV;
    char hoTen[30];
} SinhVien;

typedef struct{
    SinhVien data;
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

void push(SinhVien sv){
    if(!isFull()){
        top++;
        stack[top].data.maSV = sv.maSV;
        strcpy(stack[top].data.hoTen, sv.hoTen);
    }else{
        printf("Stack da day, khong the them phan tu\n");
    }
}

SinhVien getTop(){
    SinhVien ret;
    if(top!=-1){
        ret = stack[top].data;
    }else{
        printf("Stack da rong, khong the lay phan tu top");
        
    }
    return ret;
}

SinhVien pop(){
    SinhVien ret;
    if(!isEmpty()){
        ret = stack[top].data;
        top--;
        return ret;
    }else{
        printf("Stack da rong, khong the pop");
    }
    return ret;
}

void duyetStack(){
    printf("======== Duyet stack ======== \n");
    for(int i = top;i>=0;i--){
        printf("%5d %s\n", stack[i].data.maSV, stack[i].data.hoTen);
    }
    printf("\n");
}

int main(){
    top = -1;
    
    SinhVien sv1, sv2, sv3;
    sv1.maSV = 111;
    strcpy(sv1.hoTen, "Nguyen Van A");
    
    sv2.maSV = 222;
    strcpy(sv2.hoTen, "Nguyen Van B");
    
    sv3.maSV = 333;
    strcpy(sv3.hoTen, "Nguyen Van C");
    
    push(sv1);
    push(sv2);
    push(sv3);
    
    duyetStack();
    
    SinhVien svTop = getTop();
    printf("%5d %s\n", svTop.maSV, svTop.hoTen);
    
    pop();
    pop();
    
    duyetStack();
    
    // {([]]())}
    
    // 5+6+7
    // 5 6 7 + +
    
    sv3.maSV = 333;
    strcpy(sv3.hoTen, "Nguyen Van D");
    push(sv3);
    
    duyetStack();
    
    return 0;
}
