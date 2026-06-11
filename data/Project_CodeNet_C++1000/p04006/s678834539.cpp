#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
        node.resize(2*n-1, INF);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
  void update(int x, ll val) {
    // 最下段のノードにアクセスする
    x += (n - 1);

    // 最下段のノードを更新したら、あとは親に上って更新していく
    node[x] = val;
    while(x > 0) {
        x = (x - 1) / 2;
        node[x] = min(node[2*x+1], node[2*x+2]);
    }
  }
  ll getmin(int a, int b, int k=0, int l=0, int r=-1) {
    // 最初に呼び出されたときの対象区間は [0, n)
    if(r < 0) r = n;

    // 要求区間と対象区間が交わらない -> 適当に返す
    if(r <= a || b <= l) return INF;

    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    if(a <= l && r <= b) return node[k];

    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
    ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
    return min(vl, vr);
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, x;
  cin >> N >> x;
  vector<ll> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];

  SegmentTree segTree(a);

  ll ans = INF;
  for(int k = 0; k < N; k++){
    // k: シフト回数
    ll tmp_ans = 0;
    for(int i = 0; i < N; i++){
      //自分からシフトk回の範囲
      ll min_val = INF;

      ll tmp = segTree.getmin(max(i-k, 0), i+1);
      chmin(min_val, tmp);
      if(i < k){
        tmp = segTree.getmin(N-(k-i), N);
        chmin(min_val, tmp);
      }
      tmp_ans += min_val;
    }
    tmp_ans += k * x;
    chmin(ans, tmp_ans);
  }

  // cout << " " << endl;
  // cout << segTree.getmin(0, 1) << endl;
  // cout << segTree.getmin(0, 2) << endl;
  // cout << segTree.getmin(1, 2) << endl;

  cout << ans << endl;






  return 0;
}
