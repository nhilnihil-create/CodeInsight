#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}
int64 N;
vector<int64> G[112345];

int64 dfs(int64 v, int64 p) {
  int64 gr = 0;
  multiset<int64> st;
  REP(i, G[v].size()) {
    if (G[v][i] == p) continue;
    st.insert(dfs(G[v][i], v)+1);
  }
  if (st.size() == 0) return 0;
  if (st.size() == 1) {
    return *st.begin();
  } else {
    for (auto &x : st) {
      gr ^= x;
    }
  }
  return gr;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N-1) {
    int64 x, y;
    cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  if (dfs(0, -1)) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }
}
