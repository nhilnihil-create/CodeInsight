#include<stdio.h>

int main(){
    int n, max=0, sum=0;
    char s[105];
    scanf("%d",&n);
    scanf("%s",s);
    
    for(int i=0; i<n; i++){
        if(s[i] == 'I'){
            sum++;
        }
        if(s[i] == 'D'){
            sum--;
        }
        if(max < sum){
            max = sum;
        }
    }
    printf("%d\n",max);
    return 0;
}
