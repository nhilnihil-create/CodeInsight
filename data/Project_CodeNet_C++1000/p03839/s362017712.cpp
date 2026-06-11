#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n,k;
    cin >> n >> k;
    vector<ll> a(n),sum_a(n+1,0),sum_aplus(n+1,0);
    loop(i,n)cin >> a[i];
    rep(i,1,n+1)sum_a[i]=sum_a[i-1]+a[i-1];
    rep(i,1,n+1)sum_aplus[i]=sum_aplus[i-1]+max(0LL,a[i-1]);
    ll ans=0;
    loop(i,n-k+1){
        //i,i+1,...,i+k-1は同じ色で塗る
        ll tmp1=max(0LL,sum_a[i+k]-sum_a[i]);
        //0,...,i-1とi+k,...,n-1は任意の色で塗る
        ll tmp2=sum_aplus[i]+sum_aplus[n]-sum_aplus[i+k];
        ans=max(ans,tmp1+tmp2);
    }
    cout << ans << endl;
    return 0;
}