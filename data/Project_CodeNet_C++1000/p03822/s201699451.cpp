#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll N, ans=0, tmp=0;
vector<vector<ll>> G;

ll dfs(ll id) {
    vector<ll> v;
    for(int i=0;i<G[id].size();i++) {
        v.push_back(dfs(G[id][i]));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    tmp = 0;
    for(int i=0;i<v.size();i++) {
        tmp = max(tmp, 1+i+v[i]);
    }
    return tmp;
}

signed main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N-1;i++) {
        ll a;
        cin >> a;
        a--;
        G[a].push_back(i+1);
    }
    cout << dfs(0) << endl;
    return 0;
}