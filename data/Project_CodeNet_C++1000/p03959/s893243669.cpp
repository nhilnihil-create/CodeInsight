#include <iostream>

using namespace std;
using ll = long long;

#define rep(i,n) for(int i=0;i<(n);++i)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"
template<typename Iterator>void print(const Iterator &s, const Iterator &t) { for(auto it=s;it+1!=t;++it)cout<<*it<<" ";cout<<*(t-1)<<"\n"; }
const int MOD = 1e9+7;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; in(N);

  int T[N], A[N];
  int h[N];
  fill(h, h+N, -1);
  rep(i, N) {
    in(T[i]);
    if (i == 0 || T[i] > T[i-1])
      h[i] = T[i];
  }
  rep(i, N) in(A[i]);

  if (h[N-1] != -1 && h[N-1] != A[N-1]) {
    out(0);
    return 0;
  }
  h[N-1] = A[N-1];
  rep(i, N-1) {
    if (A[i] > A[i+1]) {
      if (h[i] == -1 || h[i] == A[i])
        h[i] = A[i];
      else {
        out(0);
        return 0;
      }
    }
  }
  rep(i, N) {
    if (h[i] != -1) {
      if (h[i] > T[i] || h[i] > A[i]) {
        out(0);
        return 0;
      }
    }
  }
  ll ans = 1;
  rep(i, N) {
    if (h[i] == -1)
      ans = (ll)(ans * min(T[i], A[i])) % MOD;
  }
  out(ans);

  return 0;
}
