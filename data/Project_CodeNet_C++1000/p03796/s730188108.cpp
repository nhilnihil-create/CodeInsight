#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll snk = 1;
  for(int i=1; i<=n; i++) {
    snk *= i;
    snk %= 1000000007;
  }
  cout << snk << endl;
  return 0;
}