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
    int n;cin >>n;
    vector<P>sc(n);
    for (int i = 0; i < n; ++i) {
        int a,b;cin >>a>>b;
        sc[i]={a,b};
    }
    sort(all(sc));
    reverse(all(sc));
    ll ans=sc[0].first+sc[0].second;
    cout <<ans<<endl;
}
