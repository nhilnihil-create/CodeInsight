#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<bool> selected(101, false);
  for (int i = 1; i < 1000; ++i) {
    int tmp = (b * i + c) % a;
    if (tmp == 0) {
      cout << "YES" << endl;
      break;
    }
    else if (selected[tmp]) {
      cout << "NO" << endl;
      break;
    }
    else {
      selected[tmp] = true;
    }
  }
}
