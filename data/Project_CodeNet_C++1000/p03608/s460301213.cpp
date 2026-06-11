#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

ll INF = (ll)pow(10, 15);

void dfs(vvl dist, vl r, vl &used, ll prev, ll depth, ll cost, ll &ans){
  if(depth == used.size() - 1){
    ans = min(ans, cost);
    return;
  }

  rep(i, used.size()){
    if(used[i] == 1) continue;

    used[i] = 1;
    dfs(dist, r, used, i, depth + 1, cost + dist[prev][r[i]], ans);
    used[i] = 0;
  }
}

int main(){
  ll N, M, R;
  cin >> N >> M >> R;
  vl r(R);
  rep(i, R) cin >> r[i];
  ll A, B, C;
  map<ll, vpll> G;
  rep(i, M){
    cin >> A >> B >> C;

    G[A].push_back({B, C});
    G[B].push_back({A, C});
  }

  vvl dist(R, vl(N + 1, INF));

  rep(i, R){
    dist[i][0] = 0;
    dist[i][r[i]] = 0;
    vl vis(N + 1, 0);
    priority_queue<pll, vpll, greater<pll>> que;
    que.push({0, r[i]});

    while(!que.empty()){
      pll top = que.top();
      que.pop();

      if(vis[top.second] == 1) continue;

      vis[top.second] = 1;
      for(auto x : G[top.second]){
	if(dist[i][x.first] > top.first + x.second)
	  dist[i][x.first] = top.first + x.second;

	que.push({dist[i][x.first], x.first});
      }
    }
  }

  ll ans = INF;
  rep(i, R){
    vl used(R, 0);
    used[i] = 1;
    dfs(dist, r, used, i, 0, 0, ans);
  }

  cout << ans << endl;
      
  return 0;
}
