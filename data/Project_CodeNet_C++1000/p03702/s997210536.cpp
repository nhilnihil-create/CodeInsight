#include<bits/stdc++.h>
#include<iomanip>
#include<numeric>

using namespace std;
using ll = long long;
constexpr int mo = 1e9+7;
constexpr int  mod = mo;
constexpr int inf = 1<<30;
bool check(ll total,int a,int b,vector<ll> & h){
    int n = (int)h.size();
    auto v = h;
    for(auto & vi : v)vi -= total*b;
    ll ret = 0ll;
    for(int i=0;i<n;++i){
        if(v[i] >0ll){
            ret += (v[i]+a-b-1ll)/(a - b);
        }
    }
    if(ret <= total) return true;
    return false;
}
int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> h(n);
    ll r = (1ll<<30)-1;
    for(auto &hi : h){ cin>>hi;}
    sort(h.rbegin(),h.rend());
    for(int i=29;i>=0;i--)if(check(r-(1ll<<i),a,b,h))r -= (1ll<<i);
    cout << r << endl;
    return 0;
}

