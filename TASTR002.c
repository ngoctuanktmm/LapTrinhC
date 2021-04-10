#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 205
 
 
int strLen(char st[]){
    int i;
    i=0;
    while (st[i] != '\0') {
        i++;
    }
    return i;
}
 
int main(){
    
    char st[MAX_LEN];
    gets(st);
    int i;
    
    int len = strLen(st);
    for(i=0;i<len;i++){
        if(st[i]>='a'&&st[i]<='z'){
            st[i] = st[i]-32;
        }
        printf("%c", st[i]);
    }
    
    return 0;
}
