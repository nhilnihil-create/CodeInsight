#include <iostream>

using namespace std;

int main() {
  int x{}, ans{};
  string X;
  cin >> X;
  for (char c : X) {
    if (c == 'T') ++x;
    else --x;
    ans = max(x, ans);
  }
  cout << 2 * ans << endl;
}
