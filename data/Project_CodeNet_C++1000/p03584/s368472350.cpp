#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main() {
   ll n,k;cin >>n>>k;
   vector<ll>a(n);
   vector<ll>b(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i]>>b[i];
    }
    ll ans=0;
    vector<int>x;
    for (int i =30; i>=0; --i) {
        if(1LL&(k>>i))x.push_back(i);
    }
    ll now=0;
    vector<ll>lis;
    lis.emplace_back(k);
    for (int i =0; i <x.size(); ++i) {
        now=0;
        for (int j = 0; j <=i; ++j) {
            now+=((1LL)<<x[j]);
        }
        now--;
        if(now>0) {
            lis.emplace_back(now);
        }
    }
    now=0;
    for (int l = 0; l < lis.size(); ++l){
        now=0;
        for (int i = 0; i < n; ++i) {
            if(lis[l]>=(lis[l]|a[i]))now+=b[i];
        }
//        cout <<lis[l]<<" "<<now<<endl;
        ans=max(ans,now);
    }
    cout <<ans<<endl;
}
