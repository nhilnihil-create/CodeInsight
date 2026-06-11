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

  ll a, b, c;
  for(int i = 0; i < M; i++){
    cin >> a >> b >> c;
    a--;
    b--;
    E[i].from = a;
    E[i].to   = b;
    E[i].cost = -c;
  }

  vector<ll> d(N);
  for(int i = 0; i < N; i++){
    d[i] = INF;
  }

  d[0] = 0;
  bool is_negative = false;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){

      edge e = E[j];

      if (d[e.to] > d[e.from] + e.cost) {  //移動した後のコストが小さいと、頂点のコストを更新
        d[e.to] = d[e.from] + e.cost;
        if (i == N-1 && e.to == N-1) {         //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
            is_negative = true;
            break;
        } 
      }
    }
  }

  if(is_negative){
    cout << "inf" << endl;
  }else{
    cout << -d[N-1] << endl;
  }

  return 0;
}
