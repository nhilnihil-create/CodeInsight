#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if (a >= b) cout << "delicious" << endl;
  else if (b - a <= x) cout << "safe" << endl;
  else cout << "dangerous" << endl;
  return 0;
}