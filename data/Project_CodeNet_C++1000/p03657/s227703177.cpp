/**
 *    author:  tourist
 *    created: 16.01.2020 23:14:00       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0 ? "Possible" : "Impossible") << '\n';
  return 0;
}
