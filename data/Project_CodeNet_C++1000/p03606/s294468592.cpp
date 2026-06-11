#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(i=0; i<n; i++)

int main() {
  int n;
  cin >> n;
  int i, l, r;
  int ans = 0;
  rep(i, n) {
    cin >> l >> r;
    ans+=r-l+1;
  }
  cout << ans << endl;
}