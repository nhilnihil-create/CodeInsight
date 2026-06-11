#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  ll a,b,c,ans;
  cin >> a >> b >> c;
  ans = b/c- a/c;
  if(a%c==0)ans++;
  cout << ans;
}