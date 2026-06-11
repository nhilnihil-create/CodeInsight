#include<bits/stdc++.h>
using namespace std;
#define N 100000 + 5
char s[N];
int len;
int main(){
    scanf("%s", s + 1);
    len = strlen(s + 1);
    if(s[1] == s[len]){
        if(len & 1) puts("Second");
        else puts("First");
    }
    else{
        if(len & 1) puts("First");
        else puts("Second");
    }
    return 0;
}