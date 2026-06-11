#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  bool f[101010] = {false};

  int sum = 0;
  for (int i = 1; sum < n; ++i) {
    sum += i;
    f[i] = true;
  }

  int d = sum - n;
  f[d] = false;

  for (int i = 0; i < 101010; ++i) {
    if (f[i]) cout << i << endl;
  }
}
