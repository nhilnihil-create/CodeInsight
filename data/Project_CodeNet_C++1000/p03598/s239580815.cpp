#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, K, s{}, x; cin >> N >> K;
  while (cin >> x) s += 2 * min(x, K - x);
  cout << s;}