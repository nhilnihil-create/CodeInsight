#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep2(i,m,n) for(int i=int(m);i<int(n);i++)
#define drep2(i,m,n) for(int i=int(m-1);i>=int(n);i--)
#define rep(i,n) rep2(i,0,n)
#define drep (i,n) drep2(i,n,0)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int MOD = int(1e9)+7;

int main()
{
    int n,m,k;cin >>n >>m>>k;
    bool flg=false;
    rep(i,n+1)rep(j,m+1){
        if(k==m*i+n*j-i*j*2)flg=true;
    }
    if(flg)puts("Yes");
    else puts ("No");
    return 0;
}
