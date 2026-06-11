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

ll N, M, R;
VVL d;
VL r;

ll dfs(map<ll, bool> cand, ll now, ll dist){
    ll ret = 1e18, cnt = 0;
    for(auto e : r){
        if(!cand[e]) continue;
        cand[e] = false;
        ret = min(ret, dfs(cand, e, dist + d[now][e]));
        cand[e] = true;
        cnt++;
    }
    if(cnt == 0) return dist;
    return ret;
}

int main(){
    cin >> N >> M >> R;
    
    r.resize(R);
    rep(i, 0, R){
        cin >> r[i];
        r[i]--;
    }

    d.resize(N, VL(N, 1e18));
    rep(i, 0, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
    }

    rep(i, 0, N) d[i][i] = 0;
    rep(i, 0, N){
        rep(j, 0, N){
            rep(k, 0, N){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }

    cerr << "toki" << endl;
    ll ans = 1e18;

    map<ll, bool> ca;
    for(auto e : r) ca[e] = true;
    for(auto e : r){
        ca[e] = false; 
        ans = min(ans, dfs(ca, e, 0));
        ca[e] = true;
    }
    cout << ans << endl;
    return 0;
}