#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  //if (a > b) {cout << 0 << endl; return 0;}

  ll mi = a * (n-1) + b;
  ll ma = a + b * (n-1);
  if (ma-mi+1 >= 0) cout << ma-mi+1 << endl;
  else cout << 0 << endl;
  return 0;
}