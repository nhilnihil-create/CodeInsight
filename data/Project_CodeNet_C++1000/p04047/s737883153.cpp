#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> L(2 * N);
  for (auto &l: L) {
    cin >> l;
  }

  sort(begin(L),end(L));
  int ans{};
  for (auto i = 0; i != N; ++i) {
    ans += L[2*i];
  }
  cout << ans << endl;
}
