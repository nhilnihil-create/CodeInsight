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

// struct LazySegmentTree {
// private:
//     int n;
//     vector<ll> lazy;

// public:
//     vector<ll> node;
//     LazySegmentTree(vector<ll> v) {
//         int sz = (int)v.size();
//         n = 1; while(n < sz) n *= 2;
//         node.resize(2*n-1);
//         lazy.resize(2*n-1, 0);

//         for(int i=0; i<sz; i++) node[i+n-1] = v[i];
//         for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
//     }
//     // k 番目のノードについて遅延評価を行う
//     void eval(int k, int l, int r) {

//     // 遅延配列が空でない場合、自ノード及び子ノードへの
//     // 値の伝播が起こる
//     if(lazy[k] != 0) {
//         node[k] += lazy[k];

//         // 最下段かどうかのチェックをしよう
//         // 子ノードは親ノードの 1/2 の範囲であるため、
//         // 伝播させるときは半分にする
//         if(r - l > 1) {
//             lazy[2*k+1] += lazy[k] / 2;
//             lazy[2*k+2] += lazy[k] / 2;
//         }

//         // 伝播が終わったので、自ノードの遅延配列を空にする
//         lazy[k] = 0;
//     }
//   }

//   void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
//     if(r < 0) r = n;

//     // k 番目のノードに対して遅延評価を行う
//     eval(k, l, r);

//     // 範囲外なら何もしない
//     if(b <= l || r <= a) return;
    
//     // 完全に被覆しているならば、遅延配列に値を入れた後に評価
//     if(a <= l && r <= b) {
//         lazy[k] += (r - l) * x;
//         eval(k, l, r);
//     }

//     // そうでないならば、子ノードの値を再帰的に計算して、
//     // 計算済みの値をもらってくる
//     else {
//         add(a, b, x, 2*k+1, l, (l+r)/2);
//         add(a, b, x, 2*k+2, (l+r)/2, r);
//         node[k] = node[2*k+1] + node[2*k+2];
//     }
// }

// ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
//     if(r < 0) r = n;
//     if(b <= l || r <= a) return 0;

//     // 関数が呼び出されたら評価！
//     eval(k, l, r);
//     if(a <= l && r <= b) return node[k];
//     ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
//     ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
//     return vl + vr;
// }

// };

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<ll> node(N);
  for(int i = 0; i < N; i++){
    node[i] = 0LL;
  }

  int a, b;
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    a--;
    b--;
    node[a]++;
    node[b]++;
  }
  bool ok = true;
  for(int i = 0; i < N; i++){
    if(node[i] % 2 == 1){
      ok = false;
      break;
    }
  }

  if(ok){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

  return 0;
}
