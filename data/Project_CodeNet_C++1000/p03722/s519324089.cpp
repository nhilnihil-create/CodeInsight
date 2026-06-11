#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

struct edge{
  int from;
  int to;
  ll cost;
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<edge> E(M);
  vector<vector<int>> G(N);
  vector<vector<int>> Gb(N);

  ll a, b, c;
  for(int i = 0; i < M; i++){
    cin >> a >> b >> c;
    a--;
    b--;
    E[i].from = a;
    E[i].to   = b;
    E[i].cost = -c;
    G[a].push_back(b);
    Gb[b].push_back(a);
  }

  vector<ll> visitG(N);
  vector<ll> visitS(N);
  for(int i = 0; i < N; i++){
    visitG[i] = -1;
    visitS[i] = -1;
  }
  queue<int> q;
  q.push(0);

  visitG[N-1] = 1;
  visitS[0]   = 1;

  while(!q.empty()){
    int next = q.front();
    q.pop();

    for(auto nv : G[next]){
      if(visitS[nv] >= 0) continue;
      
      q.push(nv);
      visitS[nv] = 1;
    }
  }

  q.push(N-1);
  while(!q.empty()){
    int next = q.front();
    q.pop();

    for(auto nv : Gb[next]){
      if(visitG[nv] >= 0) continue;
      
      q.push(nv);
      visitG[nv] = 1;
    }
  }

  vector<int> valid(N);
  for(int i = 0; i < N; i++){
    if(visitS[i] >= 0 && visitG[i] >= 0){
      valid[i] = 1;
    }else{
      valid[i] = 0;
    }
  }

  vector<ll> d(N);
  for(int i = 0; i < N; i++){
    d[i] = INF;
  }

  d[0] = 0LL;
  bool is_negative = false;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){

      edge e = E[j];

      if (d[e.to] > d[e.from] + e.cost) {  //移動した後のコストが小さいと、頂点のコストを更新
        d[e.to] = d[e.from] + e.cost; 
      }
    }
  }



  for(int i = 0; i < M; i++){
    edge e = E[i];
    if(d[e.from] + e.cost < d[e.to] && valid[e.from]){
      is_negative = true;
    }
  }

  if(is_negative){
    cout << "inf" << endl;
  }else{
    ll ans = -1 * d[N-1];
    cout << ans << endl;
  }

  return 0;
}
