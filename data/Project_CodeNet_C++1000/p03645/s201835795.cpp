#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n+1);
    rep(i,m){
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }    
    bool can = false;
    vector<ll> c1(n+1), c2(n+1);
    for(auto i:v[1]) c1[i] = 1;
    for(auto i:v[n]) c2[i] = 1;
    REP(i,1,n+1) if(c1[i]+c2[i] == 2) can = true;
    cout << (can ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    return 0;
}
