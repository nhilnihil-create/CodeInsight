#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  int n;
  cin >> n;
  ll ans=0;
  while ( n-- ) {
    int l,r;
    cin >> l >> r;
    r++;
    ans=ans+r-l;
  }
  cout << ans << '\n';
  return 0;
}