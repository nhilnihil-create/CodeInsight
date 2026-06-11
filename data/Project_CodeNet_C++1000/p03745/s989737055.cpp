#include <iostream>

using namespace std;

int main() {
  int N, A, B{}, ans{1}, d{};
  cin >> N >> B;
  while (cin >> A) {
    if (!d && A != B) d = A > B ? 1 : -1;
    else if (d * (A - B) < 0) ++ans, d = 0;
    B = A;
  }
  cout << ans << endl;
}
