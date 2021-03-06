#include <stdio.h>
#include "stdlib.h"

typedef struct TNode
{
    int data;
    struct TNode *next;
} TNode;
 
typedef struct
{
    TNode *first;
} DSLK;

void taoDanhSachLK(DSLK *dslk){
    dslk->first = NULL;
}

TNode* taoNodeMoi(int value){
    TNode *tmp;
    tmp = (TNode*)malloc(sizeof(TNode));
    
    tmp->data = value;
    tmp->next = NULL;
    
    return tmp;
}

DSLK* themVaoDauDS(DSLK *dslk, int value){
    TNode* tmp = taoNodeMoi(value);
    
    if(dslk->first==NULL){
        dslk->first = tmp;
    }else{
        tmp->next = dslk->first;
        dslk->first = tmp;
    }
    
    return dslk;
}

DSLK* themVaoCuoiDS(DSLK *dslk, int value){
    TNode *tmp = taoNodeMoi(value);
    
    if(dslk->first==NULL){
        dslk->first = tmp;
    }else{
        TNode *p;
        p = dslk->first;
        while(p->next!=NULL){
            p = p->next;
        }
        
        p->next = tmp;
    }
    
    return dslk;
}

DSLK* themVaoViTriBatKy(DSLK *dslk, int value, int viTri){
    if(viTri==0 || dslk->first==NULL){
        return themVaoDauDS(dslk, value);
    }else{
        int i=0;
        TNode *p;
        p = dslk->first;
        
        while(p!=NULL && i!=viTri){
            p = p->next;
            i++;
        }
        
        if(i!=viTri){
            dslk = themVaoCuoiDS(dslk, value);
        }else{
            TNode *tmp = taoNodeMoi(value);
            tmp->next = p->next;
            p->next = tmp;
        }
    }
    
    return dslk;
}

DSLK* xoaDauDS(DSLK *dslk){
    if(dslk==NULL){
        printf("Danh sach rong, khong co gi de xoa");
    }else{
        dslk->first = dslk->first->next;
    }
    
    return dslk;
}

DSLK* xoaCuoiDS(DSLK *dslk){
    if(dslk->first==NULL || dslk->first->next==NULL){
        return xoaDauDS(dslk);
    }else{
        TNode *p;
        p = dslk->first;
        while(p->next->next != NULL){
            p = p->next;
        }
        
        p->next = NULL;
        return dslk;
    }
}

DSLK* xoaViTriBatKy(DSLK *dslk, int viTri){
    if(viTri==0||dslk->first==NULL||dslk->first->next==NULL){
        return xoaDauDS(dslk);
    }else{
        int i=0;
        TNode *p = dslk->first;
        while(p->next != NULL && i != viTri){
            p = p->next;
            i++;
        }
        
        if(i!=viTri){
            dslk = xoaCuoiDS(dslk);
        }else{
            p->next = p->next->next;
        }
        return dslk;
    }
}

void duyetDanhSachLienKet(DSLK *dslk){
    TNode *p;
    p = dslk->first;
    
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    DSLK dslk;
    taoDanhSachLK(&dslk);
    int x;
    do{
        scanf("%d", &x);
        themVaoCuoiDS(&dslk, x);
    }while(x!=0);
    
    duyetDanhSachLienKet(&dslk);
    
    return 0;
}
