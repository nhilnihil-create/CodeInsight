#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  int64_t result = 0;
  for (int i = 1; i < N; ++i) {
    if (x < a[i - 1] + a[i]) {
      result += (a[i - 1] + a[i] - x);
      a[i] = max(x - a[i - 1], 0);
    }
  }
  cout << result << endl;
  return 0;
}
