#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int64_t res = 1LL << 60;
  for (int bit = 0; bit < (1 << N); bit++) {
    int k = 1, ma = A[0];
    int64_t cost = 0;
    for (int i = 1; i < N; i++) {
      int diff = 0;
      if ((bit >> i) & 1) {
        diff = max(0, ma - A[i] + 1);
        cost += diff;
      }
      if (chmax(ma, A[i] + diff)) k++;
    }
    if (k >= K) res = min(res, cost);
  }
  cout << res << '\n';
  return 0;
}