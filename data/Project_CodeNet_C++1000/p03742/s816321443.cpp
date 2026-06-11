/**
 *    author:  tourist
 *    created: 02.01.2020 17:44:53       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  cout << (abs(a - b) <= 1 ? "Brown" : "Alice") << '\n';
  return 0;
}
