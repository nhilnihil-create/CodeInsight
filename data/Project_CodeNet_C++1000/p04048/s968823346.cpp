#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=205;
const double eps=1e-7;

LL n,m;

LL f(LL n,LL m){
    if (m==0) return -n;
    LL ret=(n/m)*m*2;
    LL nxt=f(m,n%m);
    return ret+nxt;
}

int main(){
    scanf("%lld%lld",&n,&m);
    LL ans=n+f(n-m,m);
    printf("%lld\n",ans);
    return 0;
}