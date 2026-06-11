
#include<bits/stdc++.h>
using namespace std;
  #define ll long long
int counter(ll n)
{
    int cnt = 0 ;
    while(n)
    {
        n/=10;
        cnt++;
    }
    return cnt ;
}

int main()
{
  ll n,m;
  cin >> n ;
  int mn = INT_MAX;
  for(ll i=1; i*i<=n; i++)
  {
      if(n%i==0)
      {
          int mx = 0;
          int x = counter(i);
          int y = counter(n/i);
          mx = max(x,y);
          mn = min(mn,mx);
      }
  }

  cout << mn << endl;
}
