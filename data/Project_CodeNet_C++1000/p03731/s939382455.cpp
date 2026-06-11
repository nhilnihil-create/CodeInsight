#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const long long LINF = (1LL << 60);

int main() {
  int N, T;
  cin >> N >> T;

  vector<int> t(N);
  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }

  long long ans = T;
  for (int i = 1; i < N; i++) {
    if (t[i] - t[i - 1] >= T) {
      ans += T;
    } else {
      ans += t[i] - t[i - 1];
    }
  }
  cout << ans << endl;
  return 0;
}