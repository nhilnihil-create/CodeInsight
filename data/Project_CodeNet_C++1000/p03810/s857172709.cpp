#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
    char c = getchar();
    int p = 1;
    x = 0;
    while(!isdigit(c)){
        if(c == '-')p = -1;
        c = getchar();
    }
    while(isdigit(c)){
        x = (x << 1) + (x << 3) + (c ^ '0');
        c = getchar();
    }
    x *= p;
}
int a[100050], n;
inline bool dfs(){
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for(register int i = 1; i <= n; ++i){
        if(a[i] % 2 == 1){
            if(a[i] == 1)return 0;
            a[i]--;
            break;
        }
    }
    int GCD = a[1];
    for(register int i = 2; i <= n; ++i){
        GCD = __gcd(GCD, a[i]);
    }
    for(register int i = 1; i <= n; ++i){
        a[i] /= GCD;
    }
    for(register int i = 1; i <= n; ++i){
        if(a[i] % 2 == 0)cnt1++;
        else cnt2++;
    }
    if(cnt1 % 2 == 1)return 0;
    else{
        if(cnt2 > 1)return 1;
        else return dfs() ^ 1;
    }
}
int main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    read(n);
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for(register int i = 1; i <= n; ++i){
        read(a[i]);
        if(a[i] % 2 == 0)cnt1++;
        else cnt2++;
    }
    if(cnt1 & 1)puts("First");
    else{
        if(cnt2 > 1)puts("Second");
        else if(dfs())puts("First");
        else puts("Second");
    }
    return 0;
}