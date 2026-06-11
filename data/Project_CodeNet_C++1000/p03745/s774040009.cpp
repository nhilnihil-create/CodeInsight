/*    特徴    */

/*    教訓    */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=9223372036854775807;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-9; //微調整用（EPSより小さいと0と判定など）

//MODINT
//変数名.nでint型の数値を受け取る
struct mint {
  int n;
  mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b) { a.n += b.n; if (a.n >= MOD) a.n -= MOD; return a; }
mint operator-(mint a, mint b) { a.n -= b.n; if (a.n < 0) a.n += MOD; return a; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }

int ii() { int x; scanf("%d", &x); return x; }
long long il() { long long x; scanf("%lld", &x); return x; }
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
//GCC9.2.1に変わって動かなくなったので一旦消した そのうち原因を調べる
//auto op = [&](auto p) -> void{ cout << p; };
//auto ov = [&](auto vec) -> void{ cout << vec; };
#define o_map(v){cerr << #v << endl; for(const auto& xxx: v){cout << xxx.first << " " << xxx.second << "\n";}} //動作未確認
void br() { putchar('\n'); }

#define gcd __gcd //llは受け取ってくれない
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define ALL(a) a.begin(),a.end() //sort(ALL(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll) (n) ; i++ )
#define rep(i,n) REP(i,0,n)
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define PB push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

// coutによるpairの出力（空白区切り）
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << " " << p.second << ")";}
// 空白区切りだけ --> return s << "(" << p.first << " " << p.second << ")";
// 見やすくしたいとき --> return s << "(" << p.first << " " << p.second << ")";
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

//最大値、最小値を更新する。aよりbのが大きい（小さい）か等しければaを更新してtrueを返す。そうでなければ何もせずfalseを返す chmax(nowmax,x);
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}

// -------- template end - //


// - library ------------- //

ll comb(ll n, ll k){
  if (n < k) return 0;
  if (k > n / 2) k = n - k;
  ll ret = 1;
  ll divider = 1;
  rep(i, k) ret *= (n - i);
  rep(i, k) divider *= (i + 1);
  return ret / divider;
}

// --------- library end - //



// - main() -------------- //

int main(){
  

  ll N = il();
  vector<ll> As;
  rep(i, N){
    As.push_back(il());
  }

  int cond = 0; // 0 初期状態 1 up -1 down
  ll before = 0;
  ll ans = 1;

  for (ll a : As){
    if (cond == 0 && before == 0){
      // 初期状態なのでupもdownもない
    }
    else if (cond == 0){
      // 切った直後か、ずっと平行
      if (before < a) cond = 1;
      else if (before > a) cond = -1;
      // 同じならcond=0のまま
    }
    else if (cond == 1){
      // これまで上がってきた場合
      if (before > a){
        // 切って初期状態にする
        ans++;
        cond = 0;
      }
      // そうでなければ問題無いので、beforeを更新するだけ
    }
    else{
      // これまで下がってきた場合
      if (before < a){
        ans++;
        cond = 0;
      }
    }
    // なんにせよbeforeは更新
    before = a;
  }

  cout << ans << endl;


// ---------- main() end - //
}