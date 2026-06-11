#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n;
int num[1111];
int main(){
    cin>>n;
    n++;
    int hd, tl;
    hd = 500;
    tl = hd - 1;
    int ma = 0;
    for(int i = 0;i <= 40; i++)if(n >> i & 1)ma = i;
    int tot = 1;
    for(int i = ma - 1;i >= 0; i--){
        num[++tl] = tot;
        tot++;
        if(n >> i & 1)num[--hd] = tot, tot++;
    }
    printf("%d\n", tot * 2 - 1);
    for(int i = hd;i <= tl; i++)printf("%d ", num[i]);
    for(int i = 1;i <= tot; i++)printf("%d ", i);
    return 0;
}
