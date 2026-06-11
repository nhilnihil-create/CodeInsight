#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define _GLIBCXX_DEBUG
const int MOD = 1000000007;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  bool can = true;
  for (int i=0; i<N-1; i++) {
    if (A[i]==0&&A[i]==A[i+1]&&N%2!=0) {
      can = false;
      break;
    }
    else if (i<N-2&&A[i]==A[i+1]&&A[i+1]==A[i+2]) {
      can = false;
      break;
    }
  }
  if (can) {
    ll ans=1LL, num_same=0LL; // 同じ要素(2つ1組)の数
    for (int i=0; i<N-1; i++) {
      if (A[i]==A[i+1]) num_same++;
    }
    for (int i=0; i<num_same; i++) {
      ans *= 2LL;
      ans %= MOD;
    }
    cout << ans << endl;
  }
  else cout << 0 << endl;
}