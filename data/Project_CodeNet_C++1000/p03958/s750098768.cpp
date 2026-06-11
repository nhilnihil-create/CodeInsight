#include <bits/stdc++.h>
using namespace std;

int main()
{
  int k, t; cin >> k >> t;
  
  int a[10005];
  for (int i=1; i<=k;i++)
  {
    cin >> a[i];
  }
  
  int ans=0;
  for (int i=1; i<=k; i++)
  {
    if (a[i] > ans)
    {
      ans = a[i];
    }
  }
  ans = max(ans-1-(k-ans),0);
  cout << ans << endl;
}    