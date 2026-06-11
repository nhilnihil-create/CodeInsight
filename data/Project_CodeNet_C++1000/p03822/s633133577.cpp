#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

VVL G;

ll dfs(ll from, ll now){
    map<ll,ll> rec;
    for(auto e : G[now]){
        if(e == from) continue;
        rec[dfs(now, e) + 1]++;
    }
    ll mx = 0;
    for(auto r : rec){
        if(mx < r.first) mx = r.first + r.second - 1;
        else mx += r.second;
    }
    return mx;
}

int main(){
    ll N;
    cin >> N;
    G.resize(N+1);
    rep(i, 2, N+1){
        ll a;
        cin >> a;
        G[i].push_back(a);
        G[a].push_back(i);
    }
    cout << dfs(-1, 1) << endl;
    return 0;
}