#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int N;
  cin >> N;
  int a = 1;
  int ans = a;
  while (a <= N) {
    ans = a;
    a *= 2;
  }
    
  cout << ans << endl;

return 0;
}