#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


int main() {
  int N;
  ll a,b,c;
  cin >> N;
  vector<vector<vector<ll>>> g(N);
  rep(i,N-1) {
    cin >> a >> b >> c;
    a--;b--;
    g[a].push_back({b,c});
    g[b].push_back({a,c});
  }
  int Q,K;
  cin >> Q >> K;
  K--;

  queue<pair<int,ll>> que;
  vector<ll> ans(N,-1);
  que.push({K,0});
  while (!que.empty()) {
    auto t = que.front();
    que.pop();
    if (ans[t.first]<0) {
      ans[t.first] = t.second;
      for (auto k:g[t.first]) {
        que.push({k[0],t.second + k[1]});
      }
    }
  }
  int x,y;
  rep(i,Q) {
    cin >> x >> y;
    x--;y--;
    cout << ans[x] + ans[y] << endl;
  }
}