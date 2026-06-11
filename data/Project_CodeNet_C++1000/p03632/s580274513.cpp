#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a > c) {
    swap(a, c);
    swap(b, d);
  }
  if (b > c) {
    if (b > d) {
      cout << d - c << endl;
    } else {
      cout << b - c << endl;
    }
  } else {
    cout << 0 << endl;
  }
}