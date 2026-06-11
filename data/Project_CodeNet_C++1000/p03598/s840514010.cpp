#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (i=0; i<n; i++)

int main() {
  int n, k;
  cin >> n >> k;
  int i;
  int ans = 0;
  rep(i,n) {
    int x;
    cin >> x;
    if (2*x < k) {
      ans+=2*x;
    } else {
      ans+=(k-x)*2;
    }
  }
  cout << ans << endl;
}