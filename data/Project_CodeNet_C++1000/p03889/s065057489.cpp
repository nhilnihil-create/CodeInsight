#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>;
using namespace std;
char s[100010];
int main(){
    scanf("%s",&s);
    int k=strlen(s);
    if(k%2!=0){
        printf("No");
        return 0;
    }
    for(int i=0;i<k/2;i++){
        int u=abs(s[i]-s[k-i-1]);
        if(u!=1&&u!=2){
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}