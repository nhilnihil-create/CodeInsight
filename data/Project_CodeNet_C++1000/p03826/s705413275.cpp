#include <bits/stdc++.h>
using namespace std;

long long N, K;
vector<long long> sumV(100001);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  int A, B, C, D;
  cin >> A >> B >> C >> D;
  cout << max(A * B, C * D);
}
