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

ll INF = (ll)pow(10, 16);

int main(){
  ll N;
  cin >> N;
  ll a, b, c;
  vector<vpll> abc(N + 1);
  rep(i, N - 1){
    cin >> a >> b >> c;
    abc[a].push_back(make_pair(b, c));
    abc[b].push_back(make_pair(a, c));
  }
  ll Q, K;
  cin >> Q >> K;
  vl x(Q), y(Q);
  rep(i, Q){
    cin >> x[i] >> y[i];
  }

  vl cost(N + 1, INF);
  cost[K] = 0;
  vl vis(N + 1, 0);
  priority_queue<pll, vpll, greater<pll> > cv;
  cv.push({0, K});

  while(!cv.empty()){
    ll v1 = cv.top().first, v2 = cv.top().second;
    cv.pop();

    if(vis[v2] == 1) continue;
    
    vis[v2] = 1;
    
    rep(i, abc[v2].size()){
      ll update = abc[v2][i].second + cost[v2];
      if(update < cost[abc[v2][i].first]) cost[abc[v2][i].first] = update;
      cv.push({cost[abc[v2][i].first], abc[v2][i].first});
    }
  }

  rep(i, Q){
    cout << cost[x[i]] + cost[y[i]] << endl;
  }
  
  return 0;
}
