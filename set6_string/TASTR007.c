#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 105
 
 
int strLen(char st[]){
    int i;
    i=0;
    while (st[i] != '\0') {
        i++;
    }
    return i;
}
 
int check(char *st1, char *st2){
    int i, j;
    int len1 = strLen(st1);
    int len2 = strLen(st2);
    int flag = 0;
    
    if (len1==len2) {
        for(i=0;i<len1;i++){
            if(st1[i]!=st2[i]){
                return 0;
            }
        }
        return 1;
    }
    
    for(i=0;i<=len2-len1;i++){
        flag=1;
        for(j=0;j<len1;j++){
            if(st1[j]!=st2[i+j]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            return 1;
        }
    }
    return 0;
}
 
int main(){
    
    int T;
    char st1[MAX_LEN], st2[MAX_LEN];
    scanf("%d\n", &T);
    while (T--) {
        gets(st1);
        gets(st2);
        
        if(check(st1, st2)==0){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
    
    return 0;
}
