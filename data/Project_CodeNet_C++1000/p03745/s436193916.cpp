#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, pre, cnt = 0;
  cin >> N >> pre;
  int b = 3;
  while (cin >> A) {
    if (b == 1 && A < pre) cnt++, b = 3;
    else if (b == 2 && A > pre) cnt++, b = 3;
    else if (b == 3 && A > pre) b = 1;
    else if (b == 3 && A < pre) b = 2;
    pre = A;
  }
  cout << cnt + 1 << "\n";
}