#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x, y;
  cin >> x >> y;
  if (abs(x - y) <= 1) puts("Brown");
  else puts("Alice");
  return 0;
}
