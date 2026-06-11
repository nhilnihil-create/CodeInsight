#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(3 * N);
  for (int &x: a) cin >> x;
  sort(begin(a), end(a));
  long long ans{};
  for (int i = 0; i != N; ++i) ans += a[N+i*2];
  cout << ans << endl;
}
