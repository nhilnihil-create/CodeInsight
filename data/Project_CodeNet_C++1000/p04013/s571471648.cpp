#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define re register
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define per(i,n,m) for(int i=m;i>=n;i--)
#define rrep(i,m,n) for(register int i=m;i<=n;i++)
#define rper(i,n,m) for(register int i=m;i>=n;i--)
const int N = 3e3 + 10;
const ll mod = 1e9 + 7;
ll cnt[60][N];
int x[N];
signed main(){
    int n,a;
    si(n);
    si(a);
    rep(i,1,n)si(x[i]);
    cnt[0][0]=1;
    rep(i,1,n){
        per(k,1,i)
        rep(j,x[i],2501){
            cnt[k][j]+=cnt[k-1][j-x[i]];
        }
    }
    ll res=0;
    rep(i,1,n) {
        res+=cnt[i][i*a];
    }
    pl(res);
    return 0;
}