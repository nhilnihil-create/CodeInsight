#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  std::vector<int> vec;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    vec.push_back(x);
  }
  int now = 0, c = 0;
  for (;;) {
    if (now == 1) {
      cout << c << endl;
      break;
    }

    if (c >= n) {
      cout << -1 << endl;
      break;
    }
    c++;
    now = vec[now];
  }
}
