#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

int main() {
  ll N, ans{1};
  cin >> N;
  while (cin >> N) {
    ans = lcm(ans, N);
  }
  cout << ans << endl;
}
