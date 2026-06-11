#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  int W, a, b;
  cin >> W >> a >> b;
  if (a < b) {
    if (a + W >= b)
      cout << 0 << endl;
    else
      cout << b - (a + W) << endl;
  } else {
    if (b + W >= a)
      cout << 0 << endl;
    else
      cout << a - (b + W) << endl;
  }
}