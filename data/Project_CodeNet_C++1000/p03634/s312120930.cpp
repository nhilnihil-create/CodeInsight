#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

struct edge{
  int to;
  int cost;
};
int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<vector<edge>> to(n);
  rep(i,n-1){
    int a,b,c; cin >> a >> b >> c;
    --a;  --b;
    to[a].push_back({b,c});
    to[b].push_back({a,c});
  }
  int q,k; cin >> q >> k;
  queue<int> que;
  que.push(--k);
  vector<ll> dist(n);
  while(!que.empty()){
    int now = que.front(); que.pop();
    for(auto next : to[now]){
      if(dist[next.to] != 0) continue;
      dist[next.to] += dist[now]+next.cost;
      que.push(next.to);
    }
  }
  rep(i,q){
    int x,y; cin >> x >> y;
    cout << dist[--x]+dist[--y] << "\n";
  }
  // cout << "\n";
  return 0;
}
