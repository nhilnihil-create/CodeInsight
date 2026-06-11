#include <cstdio>
int main(){
    char a[17];
    scanf("%s",a);
    int cnt = 0;
    char b [17]= "CODEFESTIVAL2016";
    for(int i = 0;i < 17;i++){
        if(a[i]!=b[i])cnt++;
    }
    printf("%d",cnt);
    return 0;
}