#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n; cin>>n;
    vector<ll> color(9,0);
    rep(i,n){
        ll a; cin>>a;
        if(a<3200) color[a/400]++;
        else color[8]++;
    }
    ll c=0;
    rep(i,8) if(color[i]) c++;
    if(c) cout << c;
    else cout << 1;
    cout << " " << c+color[8] << endl;
    return 0;
}