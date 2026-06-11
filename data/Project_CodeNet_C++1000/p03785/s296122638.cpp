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

int ii() { int x; if (scanf("%d", &x) == 1) return x; }
long long il() { long long x; if (scanf("%lld", &x) == 1) return x; }
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

#define gcd __gcd //llは受け取ってくれない
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll) (n) ; i++ )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define p_b push_back
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

// ゼロ除算エラーの対策をしていないので注意
// 関数の引数の評価順序が未規定のため、ceil_divide(ii(), ii())はNG
ll ceil_divide(ll a, ll b) {
  return (a + b - 1) / b;
}

// --------- library end - //


// - main() -------------- //

int main(){

  ll N, C, K;
  cin >> N >> C >> K;

  vector<ll> arrivals;
  rep(i, N){
    arrivals.p_b(il());
  }

  sort(begin_end(arrivals));

  ll ans = 0;

  ll l_end = 0; // 今残っている乗客のうち一番最初に来た客の添字
  ll i = 0; // 今見ている乗客
  while (i < N){
    if (arrivals[l_end]+K == arrivals[i]){
      // 今回の客が到着したのと同時に、最初の客の我慢の限界が来た場合
      ll angry = 0; // 我慢のできない客の数
      REP(j, l_end, i){
        if (arrivals[j]+K == arrivals[i]) angry++;
      }
      // 我慢のできない客を全員載せられる数（ angry / c の切り上げ）
      ll bus_needed = ceil_divide(angry, C);
      ans += bus_needed;
      // 我慢できるできない関係なく、今見てる客まで含めて、乗れるだけ乗せる
      l_end = min(l_end + bus_needed * C, i+1);
    }
    else if (arrivals[l_end]+K < arrivals[i]){
      // 今回の客が到着する前に、最初の客の我慢の限界が来る場合
      ll angry = 0; // 我慢のできない客の数
      REP(j, l_end, i){
        if (arrivals[j]+K < arrivals[i]) angry++;
      }
      // 我慢のできない客を全員載せられる数（ angry / c の切り上げ）
      ll bus_needed = ceil_divide(angry, C);
      ans += bus_needed;
      // 我慢できるできない関係なく、今見てる客の1つ前の客までで、乗れるだけ乗せる
      l_end = min(l_end + bus_needed * C, i);
    }

    // なんにせよ、次のループでは次の客を見る
    i++;
  }

  // まだ客が残っていたら、残っている客を届けられるだけバスを出す
  ll lest = N - l_end;
  ans += ceil_divide(lest, C);

  cout << ans << endl;


// ---------- main() end - //
}