#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int sub = 0;

  int lower = max(a, c);
  int upper = min(b, d);

  cout << max(0, upper-lower) << endl;

  return 0;
}