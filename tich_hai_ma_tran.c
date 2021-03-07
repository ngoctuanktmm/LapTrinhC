#include <stdio.h>
#define MAX_ROWS    25
#define MAX_COLS    25
 
void nhapVaoMaTran(int x[][MAX_COLS], int soDong, int soCot){
    int i, j;
    
    for(i=0; i<soDong; i++){
        for(j=0; j<soCot; j++){
            scanf("%d", &x[i][j]);
        }
    }
}
 
void tinhTichHaiMaTran(int a[][MAX_COLS], int b[][MAX_COLS], int KQ[][MAX_COLS], int m, int n, int p){
    int i, j, k;
    int tmp;
    
    for(i=0; i<m; i++){
        for(k=0; k<p ;k++){
            tmp = 0;
            for(j=0; j<n; j++){
                tmp = tmp + a[i][j]*b[j][k];
            }
            KQ[i][k] = tmp;
        }
    }
}
 
void inMaTran(int x[][MAX_COLS], int soDong, int soCot){
    int i, j;
    
    for(i=0;i<soDong; i++){
        for(j=0;j<soCot; j++){
            printf("%6d", x[i][j]);
        }
        printf("\n");
    }
}
 
int main()
{
    int a[MAX_ROWS][MAX_COLS], b[MAX_ROWS][MAX_COLS];
    int KQ[MAX_ROWS][MAX_COLS];
    
    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);
    
    nhapVaoMaTran(a, m, n);
    nhapVaoMaTran(b, n, p);
    
    tinhTichHaiMaTran(a, b, KQ, m, n, p);
    
    inMaTran(KQ, m, p);
    
    return 0;
}
