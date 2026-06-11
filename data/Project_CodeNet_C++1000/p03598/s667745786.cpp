#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, k, ans=0;
  cin >> n >> k;

  int x[n];
  rep(i, n)
  {
    cin >> x[i];
  }

  rep(i, n)
  {
    ans += min(x[i]*2, abs(k-x[i])*2);
  }

  cout << ans << endl;

}
