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
    vector<vector<ll>> v(n);
    rep(i,m){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }    
    bool can = false;
    vector<bool> path1(n), path2(n);
    for(auto x: v[0]) path1[x] = true;
    for(auto x: v[n-1]) path2[x] = true;
    rep(i,n) if(path1[i] && path2[i]) can = true;
    cout << (can ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    return 0;
}
