#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1005
 
 
int strLen(char st[]){
    int i;
    i=0;
    while (st[i] != '\0') {
        i++;
    }
    return i;
}
 
void toLower(char st[]){
    int i, len;
    len = strLen(st);
    for (i=0; i<len; i++) {
        if (st[i]>='A' && st[i] <='Z') {
            st[i] = st[i] + 32;
        }
    }
}
 
int main(){
    
    char st[MAX_LEN];
    int cnt[256] = {0};
    
    gets(st);
    
    int i;
    toLower(st);
    
    for(i=0;i<strLen(st);i++){
        cnt[st[i]]++;
    }
    
    for(i=0;i<255;i++){
        if(cnt[i]!=0){
            printf("%c: %d\n", i, cnt[i]);
        }
    }
    
    return 0;
}
