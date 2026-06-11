#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=9223372036854775807;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-10; //微調整用（EPSより小さいと0と判定など）

int ii() { int x; if (scanf("%d", &x)==1) return x; else return 0; }
long long il() { long long x; if (scanf("%lld", &x)==1) return x; else return 0; }
string is() { string x; cin >> x; return x; }
char ic() { char x; cin >> x; return x; }
void oi(int x) { printf("%d ", x); }
void ol(long long x) { printf("%lld ", x); }
void od_nosp(double x) { printf("%.15f", x); } // 古い問題用
void od(double x) { printf("%.15f ", x); }
// long doubleで受け取り、fをLfなどに変えて出力すると、変な数値が出る
// それをなんとかするには独自の出力を作らなければならなそう
void os(const string &s) { printf("%s ", s.c_str()); }
void oc(const char &c) { printf("%c ", c); }
#define o_map(v){cerr << #v << endl; for(const auto& xxx: v){cout << xxx.first << " " << xxx.second << "\n";}} //動作未確認
void br() { putchar('\n'); }

// #define gcd __gcd //llは受け取らない C++17~のgcdと違うので注意
// int lcm(int a, int b){return a / gcd(a, b) * b;}
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll)(n) ; i++ )
#define DREP(i,m,n) for(ll i=(ll)(m) ; i > (ll)(n) ; i-- )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define p_b push_back
#define SZ(x) ((ll)(x).size()) //size()がunsignedなのでエラー避けに
#define endk '\n'


// coutによるpairの出力（空白区切り）
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << " " << p.second << ")";}
// coutによるvectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " "; //"\t"に変えるとTabで見やすく区切る
  }
  return s;
}
// coutによる多次元vectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << endl;
  }
  return s;
}

//最大値、最小値の更新。更新したor等しければtrueを返す
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

// -------- template end - //


// - library ------------- //



// --------- library end - //


int main(){

  ll N = il();
  vector<ll> ts;
  ts.p_b(0); // banpei
  rep(i, N){
    ts.push_back(il());
  }
  vector<ll> as;
  rep(i, N){
    as.push_back(il());
  }
  as.p_b(0); // banpei

  // T & A 's possible heights of mountains
  // [i][0|1] := i-th mountain's min|max
  vector<vector<ll> > taka(N, vector<ll>(2, 0) );
  vector<vector<ll> > ao(N, vector<ll>(2, 0) );

  // T from left to right
  rep(i, N){
    // i : 0 ~ N-1
    if (ts[i] < ts[i+1]){
      taka[i][1] = ts[i+1];
      taka[i][0] = ts[i+1];
    }
    else{
      taka[i][0] = 1;
      taka[i][1] = ts[i+1];
    }
  }


  // A from right to left
  rep(i, N){
    // i : 0 ~ N-1
    if (as[N-i] < as[N-1-i]){
      ao[N-1-i][1] = as[N-1-i];
      ao[N-1-i][0] = as[N-1-i];
    }
    else{
      ao[N-1-i][0] = 1;
      ao[N-1-i][1] = as[N-1-i];
    }
  }

  // calc ans
  ll ans = 1;
  rep(i, N){
    ll nowmax = min(ao[i][1], taka[i][1]);
    ll nowmin = max(ao[i][0], taka[i][0]);
    if (nowmax < nowmin){
      ans = 0;
      break;
    }
    else{
      ans *= nowmax - nowmin + 1;
      ans %= MOD;
    }
  }

  cout << ans << endk;

}