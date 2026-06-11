#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;


int main(){
    ll n,m;cin >>n>>m;
    vector<ll>co(n,0);
    for (int i = 0; i < m; ++i) {
        ll a,b;cin >>a>>b;
        a--;b--;
        co[a]++;co[b]++;
    }
    bool flg=true;
    for (int i = 0; i < n; ++i) {
        if(co[i]%2==1)flg=false;
    }
    if(flg)puts("YES");
    else puts("NO");
    return 0;
}