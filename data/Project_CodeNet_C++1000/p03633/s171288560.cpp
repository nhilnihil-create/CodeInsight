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
    ll lcm;
    ll g;
    for (int i = 0; i < n; ++i) {
        cin >>t[i];
        if(!i)lcm=t[i];
        g=__gcd(lcm,t[i]);
        lcm=lcm*(t[i]/g);
    }
    cout <<lcm<<endl;
    return 0;
}