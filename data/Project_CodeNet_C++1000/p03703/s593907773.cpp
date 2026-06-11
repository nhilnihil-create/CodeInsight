#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
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

struct SegmentTree {
private:
  int n;
  vector<ll> node;

public:
    // 元配列 v をセグメント木で表現する
  SegmentTree(vector<ll> v) {
    // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
    // セグメント木全体で必要なノード数は 2n-1 個である
    int sz = v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1, 0); // 最小値は-1

    // 最下段に値を入れたあとに、下の段から順番に値を入れる
    // 値を入れるには、自分の子の 2 値を参照すれば良い
    for(int i=0; i<sz; i++) node[i+n-1] = v[i];
    for(int i=n-2; i>=0; i--) node[i] = node[2*i+1] + node[2*i+2];
  }

  void update(int x, ll val) {
    // 最下段のノードにアクセスする
    x += (n - 1);

    // 最下段のノードを更新したら、あとは親に上って更新していく
    node[x] = val;
    while(x > 0) {
      x = (x - 1) / 2;
      node[x] = node[2*x+1] + node[2*x+2];
    }
  }

    // 要求区間 [a, b) 中の要素の最大値を答える
    // k := 自分がいるノードのインデックス
    // 対象区間は [l, r) にあたる
  ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
    // 最初に呼び出されたときの対象区間は [0, n)
    if(r < 0) r = n;

    // 要求区間と対象区間が交わらない -> 適当に返す
    if(r <= a || b <= l) return 0;

    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    if(a <= l && r <= b) return node[k];

    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
    ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
    return vl + vr;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  ll k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n){
    cin >> a[i];
    a[i] -= k;
  }

  vector<ll> suma(n+1);
  suma[0] = 0;
  rep(i, n){
    suma[i+1] = suma[i] + a[i];
  }

  set<ll> st;
  rep(i, n+1){
    st.insert(suma[i]);
  }

  map<ll, int> mp;
  int ind = 0;
  for(auto val : st){
    mp[val] = ind;
    ind++;
  }

  SegmentTree sg(vector<ll>(n+1, 0));

  ll ans = 0;
  for(int i = n; i >= 0; i--){

    int ind = mp[suma[i]];
    
    ans += sg.getsum(ind, n+1);

    ll val = sg.getsum(ind, ind+1);
    sg.update(ind, val+1);

  }

  cout << ans << endl;

  return 0;
}
