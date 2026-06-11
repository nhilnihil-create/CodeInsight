#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n,k;cin >>n>>k;
    ll g=0;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        g=__gcd(g,a[i]);
    }
    bool flg=false;
    for (int i = 0; i < n; ++i) {
        ll d=a[i]-k;
        if(d<0)continue;
        if(d%g==0)flg=true;
    }
    if(flg)puts("POSSIBLE");
    else puts("IMPOSSIBLE");
    return 0;
}
