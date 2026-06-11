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
  string S = is();

  // 羊 : 0, 狼 : 1, とする

  // ansc : 答えの候補を作る
  // ansc[0~3] : N-1匹目 と 0匹目 が 00, 01, 10, 11 の場合で試す
  // ansc[0~3][0 ~ N+1] の中身 : [動物N-1, 動物0, 1, ..., 動物N-1, 動物0]
  vector<vector<ll> > ansc(4, vector<ll>(N+2, 0));

  ansc[0][0] = 0;
  ansc[0][1] = 0;
  ansc[1][0] = 0;
  ansc[1][1] = 1;
  ansc[2][0] = 1;
  ansc[2][1] = 0;
  ansc[3][0] = 1;
  ansc[3][1] = 1;

  ll ans = -1;
  rep(i, 4){
    // i : 0 ~ 3
    REP(j, 2, N+2){
      // j : 2 ~ N+1
      // j = 0, 1 の場合は既に決まっているので、そこから右を当てはめていく
      // 矛盾したら、それは答えではないので抜ける
      ll nowansc; // j番目の答えとしてあるべきもの

      // j = 2 の答えを求めるためには、S[0] と ansc[i][0]を見る
      // つまり、j の答えを求めるためには、S[j-2] と ansc[i][j-2]を見る
      if (S[j-2] == 'o') nowansc = ansc[i][j-2];
      else nowansc = ansc[i][j-2] ^ 1; // ビットで反転
      // 一つ前（ansc[i][j-1]）が狼なら更に反転
      if (ansc[i][j-1]==1) nowansc ^= 1;
      // ここで、nowansc に 順番に見てきた結果の「N, 0番目の動物が羊(0)か狼(1)か」が入っている。矛盾するかどうか？ 矛盾すればbreak, 両方とも矛盾しなければOK
      if (j == N){
        if (nowansc != ansc[i][0]) break;
        else ansc[i][j] = nowansc;
      }
      else{
        ansc[i][j] = nowansc;
      }
      if (j == N+1){
        if (nowansc != ansc[i][1]) break;
        else ans = i;
      }
    }
    // ansが変わっていたら、答えが出たということ
    if (ans != -1){
      // 答えの出力
      REP(i, 1, N+1) cout << (ansc[ans][i] == 0 ? 'S' : 'W');
      br();
      return 0;
    }
  }

  // 抜けたということは、ansはずっと-1であったということ
  cout << -1 << endk;

}