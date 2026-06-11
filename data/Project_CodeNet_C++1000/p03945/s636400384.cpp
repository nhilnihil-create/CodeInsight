#include <iostream>

using namespace std;

int main() {
  char last = '1';
  char c;
  int ans = -1;
  while (cin >> c) {
    ans += c != last;
    last = c;
  }
  cout << ans << endl;
}