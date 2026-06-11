#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, ans=0;
  cin >> n;
  int a[n];

  rep(i, n)
  {
    cin >> a[i];
  }

  int i = 0;
  while(true)
  {
    ans++;

    if(ans > n)
      break;

    if(a[i] == 2)
    {
      cout << ans << endl;
      break;
    }

    i = a[i]-1;
  }

  if(ans > n)
    cout << -1 << endl;

}
