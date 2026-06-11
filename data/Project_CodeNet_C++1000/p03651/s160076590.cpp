#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main(int argc, char* argv[]) {
  long long N, K;
  cin >> N >> K;

  vector<long long> a(N);
  long long maximum = 0;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    maximum = max(a[i], maximum);
  }

  if (maximum < K) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  long long g = a[0];
  for (int i = 1; i < N; ++i) {
    g = gcd(g, a[i]);
  }

  if (g <= K && K % g == 0) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}