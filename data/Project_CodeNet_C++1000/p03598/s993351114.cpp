#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;

  vector<int> x(n);
  rep(i,n) cin >> x[i];

  int answer = 0;
  for (int i = 0; i < n; i++) {
    int min_dist = min(abs(x[i]), abs(x[i] - k));
    answer += min_dist * 2;
  }
  cout << answer << '\n';
}
