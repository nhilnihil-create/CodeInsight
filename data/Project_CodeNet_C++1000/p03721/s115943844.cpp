#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
template <typename T>
T sq(T x){
  return x * x;
}
const int AMAX = 100000;
ll cnt[AMAX + 1];
int main(void) {
  int N;
  ll K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    int A, B;
    cin >> A >> B;
    cnt[A] += B; }
  for (int ans = 1; ans <= AMAX; ++ans){
    if (K <= cnt[ans]) {
      cout << ans << endl;
      break; }
    K -= cnt[ans]; }
  return 0;
}
