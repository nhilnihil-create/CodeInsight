#include<bits/stdc++.h>
using namespace std;
char a[100010],b[100010];
int main(void){
    scanf("%s",a+1);
    int cnt=0;
    for(int i=strlen(a+1);i>=1;i--){
        b[++cnt]=a[i];
    }
    for(int i=1;i<=strlen(a+1);i++){
        if(a[i]=='b') a[i]='d';
        else if(a[i]=='d') a[i]='b';
        else if(a[i]=='p') a[i]='q';
        else if(a[i]=='q') a[i]='p';
    }
    for(int i=1;i<=strlen(a+1);i++){
        if(a[i]==b[i]) continue;
        else{
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}