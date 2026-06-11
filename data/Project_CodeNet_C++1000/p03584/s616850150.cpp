#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define ll long long
using namespace std;
const int N=1e6+6;
int n,a[N],b[N];
ll calc(ll k){
    ll s=0; rep(i,1,n) if ((a[i]&k)==a[i]) s+=b[i]; return s;
}
int main(){
    int k; scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d%d",&a[i],&b[i]);
    ll ans=calc(k);
    for (int j=1;j<=k;j<<=1)
        if (k&j) k-=j,k|=j-1,ans=max(ans,calc(k));
    cout<<ans<<endl;
    return 0;
}
