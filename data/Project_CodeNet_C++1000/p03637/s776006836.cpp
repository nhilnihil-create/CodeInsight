#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int odd = 0, even = 0, four = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a & 1) {
      odd++;
    } else {
      even++;
    }
    if (a % 4 == 0) {
      four++;
    }
  }

  bool is_ok = true;
  if (odd > four + 1) {
    is_ok = false;
  } else if (odd == four + 1) {
    if (four == even) {
      is_ok = true;
    } else {
      is_ok = false;
    }
  } else {
    is_ok = true;
  }
  cout << (is_ok ? "Yes" : "No") << endl;

  return 0;
}