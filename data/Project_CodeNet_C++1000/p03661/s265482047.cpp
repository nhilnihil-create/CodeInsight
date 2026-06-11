#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    sum += A[i];
  }
  
  vector<ll> dp(N - 1, 0);
  ll x = 0, y = 0;
  for (int i = 0; i < N - 1; ++i) {
    x += A[i];
    y = sum - x;
    dp[i] = abs(x - y);
  }
  cout << *min_element(dp.begin(), dp.end()) << endl;
}