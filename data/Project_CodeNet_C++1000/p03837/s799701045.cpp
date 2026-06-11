#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> d(N+1, vector<ll>(N+1, 1e18));
    vector<pair<ll,ll>> edge(M);
    vector<ll> cost(M);
    rep(i, 0, M){
        ll a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
        edge[i] = {a, b};
        cost[i] = c;
    }
    rep(i, 1, N+1) d[i][i] = 0;
    rep(i, 1, N+1){
        rep(j, 1, N+1){
            rep(k, 1, N+1){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    vector<bool> v(M, false);
    rep(i, 1, N){
        rep(j, i+1, N+1){
            rep(k, 0, M){
                ll a = edge[k].first;
                ll b = edge[k].second;
                if(d[i][b] + cost[k] + d[a][j] == d[i][j]) v[k] = true;
                if(d[i][a] + cost[k] + d[b][j] == d[i][j]) v[k] = true;
            }
        }
    }
    ll ans = 0;
    rep(i, 0, M){
        if(!v[i]){
            cerr << i << endl;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}