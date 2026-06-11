#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<ll>;
using VV = vector<VI>;
using VS = vector<string>;

// tourist set
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// tourist set end

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,b) FOR(i, 0, b)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<'\n'
#define p2(s, t) cout << (s) << " " << (t) << '\n'
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << '\n'
#define p_yes() p("YES")
#define p_no() p("NO")
#define SZ(x) ((int)(x).size())

void no(){p_no(); exit(0);}
void yes(){p_yes(); exit(0);}

const ll mod = 1e9 + 7;
const ll inf = 1e18;

struct Edge{
    ll to;
    ll cost;
    Edge(ll to, ll cost): to(to), cost(cost) {}
    Edge(){}
};

struct BellmanFord{
    vector<vector<Edge> > edges;
    vector<ll> dist;
    
    BellmanFord(ll sz){
        edges.resize(sz);
        dist.resize(sz, inf);
    }

    void add_edge(ll a, ll b, ll c){
        edges[a].push_back(Edge(b, c));
    }

    // 計算量 V * E
    vector<ll> calc_shortest_path(ll start){
        dist[start] = 0;
        ll N = dist.size();
        ll loop = N - 1;
        while(loop--){
            FOR(i, 0, N){
                if(dist[i]==inf) continue;
                for(auto edge : edges[i]){
                    chmin(dist[edge.to], dist[i] + edge.cost);
                }
            }
        }

        vector<bool> changed(N, false);
        // negative check
        FOR(i, 0, N){
            if(dist[i]==inf) continue;
            for(auto edge : edges[i]){
                if(dist[i] + edge.cost < dist[edge.to]){
                    changed[edge.to] = true;
                }
            }
        }
        // changedの伝播
        FOR(i, 0, N){
          if(dist[i]==inf) continue;
          for(auto edge : edges[i]){
            // iから edge.toへ
            if(changed[i]){
              changed[edge.to]=true;
            }
          }
        }

        // N-1のみ合ってればいいので
        if(changed[N-1]){ // いくらでも大きくできる
          dist[N-1]=-1; // -1を印とする
        }

        return dist;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll V, E;
    cin >> V >> E;
    ll N = V;

    auto bf = BellmanFord(V);

    FOR(i, 0, E){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        c = -c;
        bf.add_edge(a, b, c);
    }

    auto lis = bf.calc_shortest_path(0);
    if(lis[N-1]==-1){
      p("inf");
    }else{
      p(-lis[N-1]);
    }
    
    return 0;
}