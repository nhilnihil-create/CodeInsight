/**
 *    author:  tourist
 *    created: 29.12.2019 22:19:18       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  int k = 1;
  int s = 0;
  while (true) {
    s += k++;
    if (s >= x && s % 1 == x % 1) break;
  }
  cout << k - 1 << '\n';
  return 0;
}
