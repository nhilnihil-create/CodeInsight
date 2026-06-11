#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  cout << (((k < n) ? ((k * x) + (n - k) * y) : (n * x))) << endl;
  getchar();
}