#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


int main() {
  ll N,M,a,b,c;
  cin >> N >> M;
  vector<vector<vector<ll>>> g(N);
  rep(i,M) {
    cin >> a >> b >> c;
    a--;b--;
    g[a].push_back({b,c});
    g[b].push_back({a,c});
  }

  int res=0;
  rep(i,N){
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
    vector<ll> ans(N,LONG_LONG_MAX/100);
    pq.push({0,i});//cost、場所
    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      if (ans[t[1]]>t[0]){
        ans[t[1]] = t[0];
        for (auto e:g[t[1]]) {
          pq.push({t[0] + e[1] ,e[0]});
        }
      }
    }
    for (auto e:g[i]) {
      if (e[1]>ans[e[0]]) res++;
    }
  }
  cout << res/2 << endl;
}