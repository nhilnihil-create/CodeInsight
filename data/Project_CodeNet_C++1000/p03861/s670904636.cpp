#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  ll a, b, x;
  cin >> a >> b >> x;

  cout << (b / x) - (a + x - 1) / x + 1 << "\n";
}
