#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int N;
  cin >> N;
  auto v = vector<int>(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  v.emplace_back(0);
  int s = accumulate(v.begin(), v.end(), 0);
  sort(v.begin(), v.end());
  for (int i = 0; i < N; i++) {
    if ((s - v[i]) % 10 != 0) {
      cout << s - v[i] << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}
