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
   ll n;cin >>n;
   vector<ll>t(n);
    for (int i = 0; i < n; ++i) {
        cin >>t[i];
    }
    ll ans=t[0];
    ll g=0;
    for (int i = 0; i < n; ++i) {
        g=__gcd(ans,t[i]);
        ans=t[i]*(ans/g);
//        cout <<ans <<endl;
    }
    cout<<ans <<endl;
   return 0;
}