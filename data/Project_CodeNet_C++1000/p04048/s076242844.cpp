/**
 *    author:  tourist
 *    created: 25.01.2020 20:41:36       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, x;
  cin >> n >> x;
  cout << 3 * (n - __gcd(n, x)) << '\n';
  return 0;
}
