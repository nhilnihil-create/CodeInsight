#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}

template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}


const int MOD = 1000000007;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;

void addM(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void mulM(long long &a, long long b) {
    a = ((a%MOD)*(b%MOD))%MOD ;
}

int main() {
    int n;
    cin >> n;

  auto g = make_vec<ll>(n, n);
  auto g2 = make_vec<ll>(n, n);
  REP(i, n) REP(j, n) {
    cin >> g[i][j];
    g2[i][j] = g[i][j];
  }

  REP(k, n) REP(i, n) REP(j, n) chmin(g[i][j], g[i][k] + g[k][j]);

  bool flg = true;
  ll ans = 0;
  REP(i, n) for(int j = i + 1;j < n; j++) {
    if(g[i][j] != g2[i][j]) flg = false;
    
    bool ok = true;
    REP(k, n) {
      if(i == k || j == k) continue;
      if(g[i][j] == g[i][k]+g[k][j]) {
        ok = false;
        break;
      }
    }
    if(ok) ans += g[i][j];
  }

  cout << (flg ? ans : -1) << endl;

  return 0;
}
