#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, x = 0, t = 1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    x += (a - 1) / t;
    if (t == 1 || t == a) t++;
  }
  cout << x << endl;
}
