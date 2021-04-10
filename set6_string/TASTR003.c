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
 
int main(){
    
    char st[MAX_LEN], c;
    gets(st);
    scanf("%c", &c);
    int i, dem=0;
    
    int len = strLen(st);
    for(i=0;i<len;i++){
        if(st[i]>='a'&&st[i]<='z'){
            st[i] = st[i]-32;
        }
    }
    if(c>='a' && c<='z'){
        c = c-32;
    }
    for(i=0;i<len;i++){
        if(c==st[i]){
            dem++;
        }
    }
    
    printf("%d", dem);
    
    return 0;
}
