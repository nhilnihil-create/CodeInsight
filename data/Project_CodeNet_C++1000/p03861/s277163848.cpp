#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  ll a, b, x;
  cin >> a >> b >> x;

  if (a % x != 0) a += x - (a % x);
  if (b % x != 0) b -= b % x;
  ll d = b - a;

  ll res = a <= b ? d / x + 1: 0;
  cout << res << "\n";
}
