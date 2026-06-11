#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  vector<ll> sum(N); // 累積和
  sum[0] = A[0];
  for (int i=1; i<N; i++) sum[i] = sum[i-1]+A[i];
  int res = N;
  for (int i=N-2; i>=0; i--) {
    if (2*sum[i]<A[i+1]) {
      res = N-i-1;
      break;
    }
  }
  cout << res << endl;
  return 0;
}