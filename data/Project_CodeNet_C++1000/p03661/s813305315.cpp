#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int N; cin >> N;
  vector<long long> a(N + 1); for (int i = 1; i <= N; i++) cin >> a[i];
  for (int i = 2; i <= N; i++) a[i] += a[i - 1];
  long long ans = 200000000000001;
  for (int i = 1; i < N; i++) ans = min(abs(a[i] - (a[N] - a[i])), ans);
  cout << ans << endl;
  return 0;
}