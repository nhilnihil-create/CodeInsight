#define LOCAL
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rrep(i, n) for(int i=(n-1); i>=0; --i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
static const int INTINF = (INT_MAX >> 1); // 10^9 + 10^7
static const ll LLINF = (LLONG_MAX >> 1);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

struct edge {
  ll to, cost;
};
typedef pair<ll, ll> P;

ll V;
vector<edge> G[MAX]; // 頂点iのedgeを格納
ll d[MAX];

void dijkstra(ll s){
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, LLINF);
    d[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;
        for(ll i=0; i<G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                // 更新
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }

    // dがsからの各頂点への最短距離なので
    // rep(i, V){
    //     cout << d[i] << endl;;
    // }
}


int main(int argc, const char * argv[]) {
  std::cout << std::fixed << std::setprecision(15);

  int N; cin >> N;
  V = N;
  rep(i, N-1){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }

  int Q, K; cin >> Q >> K;
  K--;

  dijkstra(K);

  rep(i, Q){
    ll x, y; cin >> x >> y;
    x--; y--;
    ll ans = d[x] + d[y];
    cout << ans << endl;
  }
}  
