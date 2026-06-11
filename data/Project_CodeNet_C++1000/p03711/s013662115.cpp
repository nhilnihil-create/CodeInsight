#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  int x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "Yes" << endl;
    return 0;
  }
  set<int> a = { 1, 3, 5, 7, 8, 10, 12 };
  set<int> b = { 4, 6, 9, 10, 11 };
  if ((a.count(x) > 0 && a.count(y) > 0) || (b.count(x) > 0 && b.count(y))) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}