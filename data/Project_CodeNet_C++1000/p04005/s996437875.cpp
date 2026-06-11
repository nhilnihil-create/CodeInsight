#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll A, B, C, ans{};
  cin >> A >> B >> C;
  if (A % 2 && B % 2 && C % 2) {
    ans = min({A*B,B*C,C*A});
  }
  cout << ans << endl;
  return 0;
}
