#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

// 転倒数: https://scrapbox.io/pocala-kyopro/%E8%BB%A2%E5%80%92%E6%95%B0
// バブルソートの交換回数は、狭義単調減少の転倒数と一致する

// 手数がやや多い

// 各aからkを引いて、算術平均k以上ではなく、0以上の区間を求める
// 累積和を使えば、そのような区間の数は各jにおいて、i<jかつs_j-s_i>=0を満たすiの和
// BITを使って転倒数を求めるのとほぼ同様の手法で、上記のiの個数を高速に数え上げることが可能
// 今回は取り得る要素の最大値が10^9と大きいので、BITの長さを圧縮するために要素の種類数でBITを扱う

// 累積和sの種類数について
// 種類数は高々N+1にしかならない(配列の長さからも自明だが)
// 累積和sが重複ない場合は、例えばaの全要素が1の場合であるが、このときs={0,1,2,3,...,n}である
// この時がsが種類数が最大となる場合である

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll n,k; cin>>n>>k;
  
  // 数列aにおいて算術平均がk以上の区間とは、aの各々の要素からkを引いた時の算術平均0以上の区間と同値である
  // よって、累積和を使いs_j-s_i>=0以上である区間の数を数え上げることで解を求める
  vll s(n+1);
  rep(i,n){
    ll a; cin>>a;
    a-=k;
    s[i+1]=s[i]+a;
  }
  
  auto ss=s;
  vsort(ss);
  // uniqueはユニークな要素を配列の先頭に集める関数(重複要素を実際に削除することはしない)
  // 戻り値としてユニークな要素の末尾のindexが返されるので、これと配列のendまでの要素を指定してeraseすることで重複を除いた配列が得られる
  // 対象の配列は事前にソートしておく必要あり
  ss.erase(unique(all(ss)),ss.end());
  
  BIT<ll> bit(n+10);
  ll ans=0;
  rep(i,n+1){
    
    // 今j番目の累積和s_jを見ているとする
    // 算術平均がk以上となるのは、i<jかつs_j-s_i>=0なるiの個数に対応する
    // かみ砕くと、s_j-s_i>=0からs_j>=s_iであるので、つまりjより前でs_j以下の要素の個数kとすると求める個数はΣkとなる
    // ここで、jにおいてs_j以下の個数のカウントは転倒数とほぼ同様にBITを使って求めることができる
    // 転倒数は各jについてi<jかつa_i>a_jなるiの個数をカウントするが、ここではs_i<=s_jなるiの個数をカウントする
    // これは単純にbit.sum(s[j])をカウントすればよい
    // しかし、a_i<=10^9という制約があるため、BITの長さを要素の最大値とすることはできない
    // ここでBITの長さを圧縮することを考える
    // 今、BITの用途は「jより前においてs_j以下の要素の個数を知る」ことである
    // つまり今の値との大小比較ができればよいので、BITの長さは要素の取りうる値の範囲でなくとも、要素の種類数で良いとわかる
    // この考えでBITの長さを取ると長さは高々Nとなり、今回のN<=2*10^5の都合に合う
    // このidはsにおいて「何番目に大きい要素か」を意味する。この番号は0-index始まりであることに注意する
    ll id=lower_bound(all(ss),s[i])-ss.begin();
    
    // id番目以下の大きさである要素数をカウントする
    // BITは1-index始まりであることに注意する(id=0ならばbit.sum(1)を参照する必要がある)
    ans+=bit.sum(id+1);
    
    // BITに今見ているs_jの要素の順番を追加する
    bit.add(id+1,1);
  }
  cout<<ans<<endl;
}