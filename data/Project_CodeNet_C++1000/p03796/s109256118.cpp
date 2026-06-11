#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long N, M = 1e9+7;
  cin >> N;
  long now = 1, cnt = 1;
  while (N--) now *= cnt++, now %= M;
  cout << now << "\n";
}