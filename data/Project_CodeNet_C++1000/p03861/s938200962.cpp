#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  unsigned long long a, b, x;
  cin >> a >> b >> x;
  cout << ((unsigned long long)(b / x - a / x + !(a % x))) << endl;
  getchar();
}