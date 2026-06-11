#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;

int main(){
  int N; cin >> N;
  vector<vector<pair<int,ll>>> G(N);
  rep(i,N-1){
    int a, b; cin >> a >> b;
    ll c; cin >> c;
    --a, --b;
    G[a].push_back({b,c});
    G[b].push_back({a,c});
  }

  int Q, K; cin >> Q >> K;
  --K;

  // Kを始点としたBFS
  queue<int> q;
  q.push(K);
  vector<ll> dist(N, -1);
  dist[K] = 0;
  while (!q.empty()){
    int v = q.front(); q.pop();
    for (auto p : G[v]){
      if (dist[p.first]!=-1) continue;

      dist[p.first] = dist[v] + p.second;
      q.push(p.first);
    }
  }
  rep(i,Q){
    int x, y; cin >> x >> y;
    --x, --y;
    ll ans = dist[x] + dist[y];
    cout << ans << endl;
  }
  
  // cout << fixed << setprecision(10);
  
  return 0;
}
