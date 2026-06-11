#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
long long MOD = 1000000000 + 7;
 
template<typename T>
T gcd(T a, T b) {
  if(a < b) swap(a,b);
    
  if(b == 0) return a;
  return gcd(b, a % b);
}
// セグメントツリー
typedef long long ll;
int const inf = INT_MAX / 2;
 
enum query_type { min_query, max_query, sum_query, gcd_query};
 
template<class T> struct segtree {
  int N;
  vector<T> dat, sum;
  function<T(T, T)> func;
  T ngvalue;
 
  void init(int n, function<T(T, T)> const& f, T ng) {
    N = 1;
    while(N < n) N <<= 1;
    dat.assign(2 * N - 1, 0);
    sum.assign(2 * N - 1, 0);
    func = f;
    ngvalue = ng;
  }
 
  segtree() = default;
 
  segtree(int n, query_type qtype) {
    if(qtype == min_query) {
      init(n, [](T a, T b){return min(a, b);}, numeric_limits<T>::max());
    }
    else if(qtype == max_query) {
      init(n, [](T a, T b){return max(a, b);}, numeric_limits<T>::min());
    }
    else if(qtype == sum_query) {
      init(n, [](T a, T b){return a + b;}, 0);
    }
    else if(qtype == gcd_query) {
      init(n, [](T a, T b){return gcd(a,b);}, 0);
    }
    else {
      runtime_error("no matching query type");
    }
  }
 
  void add(int i, T x) {
    add(i, i + 1, x);
  }
 
  void add(int a, int b, T x) {
    add(a, b, x, 0, 0, N);
  }
 
  T add(int a, int b, T x, int k, int l, int r) {
    if(b <= l || r <= a) return dat[k];
    if(a <= l && r <= b) {
      sum[k] += x;
      return dat[k] += x;
    }
    int m = (l + r) / 2;
    return dat[k] = func(add(a, b, x, 2 * k + 1, l, m), add(a, b, x, 2 * k + 2, m, r)) + sum[k];
  }
 
  T operator()(int a, int b) {
    return query(a, b, 0, 0, N);
  }
 
  T query(int a, int b, int k, int l, int r) {
    if(b <= l || r <= a) return ngvalue;
    if(a <= l && r <= b) return dat[k];
    int m = (l + r) / 2;
    return func(query(a, b, 2 * k + 1, l, m), query(a, b, 2 * k + 2, m, r)) + sum[k];
  }
};


int main(){
  cout << setprecision(10);
  int N;
  ll K;
  cin >> N >> K;

  segtree<int> st(N+2, sum_query);

  vector<ll> S(N);
  for(int i = 0; i < N; i++){
    cin >> S[i];
    S[i] -= K;
  }
  vector<ll> SS(N+1), SSS(N+1);
  SS[0] = 0;
  for(int i = 0; i < N; i++){
    SS[i+1] = SS[i] + S[i];
  }

  map<ll,int> m;
  SSS = SS;
  sort(SS.begin(), SS.end());
  for(int i = 0; i <= N; i++){
    if(m.count(SS[i]) == 0){
      m[SS[i]] = i;
    }
  }

  vector<int> target(N+1);
  for(int i = 0; i <= N; i++){
    target[i] = m[SSS[i]] + 1;
    // cerr << "SS: " << SSS[i] << " rank: " << target[i] << endl;
  }

  // target[i]を足した時に、0~i-1でtarget[i]以下の個数を足していく
  ll ans = 0;
  for(int i = 0; i <= N; i++){
    ans += st(0, target[i]+1);
    // cerr << "i: " << i << " target[i]: " << target[i] << " now: " << st(target[i], target[i]+1) << " query: " << st(0, target[i]+1) << endl;
    st.add(target[i], 1);
  }
  cout << ans << endl;
  


}
