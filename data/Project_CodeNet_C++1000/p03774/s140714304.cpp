#include <bits/stdc++.h>
using namespace std;
bool PN(int x)
{
  if (x <= 1)
    return false;
  if (x == 2)
    return true;
  for (int i = 2; i < sqrt(x) + 1; i++)
    if (x % i == 0)
      return false;
  return true;
}

void solve()
{
  int n, m; cin >> n >> m;
  int a[n], b[n];
  int x[m], y[m];
  for(int i = 0; i < n; ++i){
    cin >> a[i] >> b[i];
  }
  for(int i = 0; i < m; ++i){
    cin >> x[i] >> y[i];
  }
  for(int i =0 ; i < n; ++i){
    int mi = 1000500000;
    int ans = -1;
    for(int j = 0; j < m; ++j){
      if(mi > abs(a[i]-x[j]) + abs(b[i]-y[j])){
        ans = j+1;
        mi = abs(a[i]-x[j]) + abs(b[i]-y[j]);
      }
    }

    cout << ans << endl;
  }
}

int main()
{
  solve();
  return 0;
}