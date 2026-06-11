#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  
  ll sum = 0, res1 = 0;
  if(a[0] > 0)
  {
    sum = a[0];
  }
  else
  {
    sum = 1;
    res1 += 1 - a[0];
  }
  for(int i = 1; i < n; i++)
  {
    sum += a[i];
    if(i % 2 == 1 && sum >= 0)
    {
      res1 += sum + 1;
      sum = -1;
    }
    else if(i % 2 == 0 && sum <= 0)
    {
      res1 += 1 - sum;
      sum = 1;
      
    }
    //cout << sum << " " << res1 << endl;
  }
  
  sum = 0;
  ll res2 = 0;
  if(a[0] < 0) sum = a[0];
  else
  {
    res2 += 1 + a[0];
    sum = -1;
  }
  for(int i = 1; i < n; i++)
  {
    sum += a[i];
    if(i % 2 == 1 && sum <= 0)
    {
      res2 += 1 - sum;
      sum = 1;
    }
    else if(i % 2 == 0 && sum >= 0)
    {
      res2 += 1 + sum;
      sum = -1;
    }
    //cout << sum << " " << res2 << endl;
  }
  cout << min(res1, res2) << endl;

  
  return 0;
}