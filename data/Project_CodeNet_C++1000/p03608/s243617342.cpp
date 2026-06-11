#include <bits/stdc++.h>

#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9+7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

ll n, m, r;
ll dist[222][222];
ll town[10];

ll ans = LINF;
bool used[222] = {};

void dfs(ll pos, ll path_dist, ll depth){
    if(depth == r){
        ans = min(ans, path_dist);
    }

    rep(i, r)if(!used[town[i]]){
        used[town[i]] = true;
        dfs(town[i], path_dist+dist[pos][town[i]], depth+1);
        used[town[i]] = false;
    }
}

int main(){
    cin >> n >> m >> r;

    rep(i, r){
        cin >> town[i];
        town[i]--;
    }

    //最短距離テーブルの初期化
    rep(i, n)rep(j, n)dist[i][j] = LINF;

    rep(i, m){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }

    //ワーシャルフロイド法で各組の最短距離を更新
    rep(k, n){//中間点
        rep(i, n){//始点
            rep(j, n){//終点
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    rep(i, r){
        used[town[i]] = true;
        dfs(town[i], 0, 1);
        used[town[i]] = false;
    }

    cout << ans << endl;
}