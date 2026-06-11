#include<stdio.h>

int main(void){
    int i,pa,pz,n;
    char s[200000],a = 'A',z = 'Z';
    
    scanf("%s",s);
    for(i = 0; s[i] != '\0'; i++);
    n = i;
    pz = n;
    for(i = 0; i < n; i++){
        if(s[i] == a){
        pa = i;
        break;
        }
    }
    for(i = n;i > 0;i--){
        if(s[i] == z){
            pz = i;
            break;
        }
    }
    n = pz - pa + 1;

    printf("%d",n);
    
    return 0;
}