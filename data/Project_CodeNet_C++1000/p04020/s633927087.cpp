#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int i;
  rep(i,n) cin >> a[i];
  ll ans = 0;
  rep(i,n-1)
  {
    if(a[i]%2 == 1 && a[i+1] != 0)
    {
      a[i]--;
      a[i+1]--;
      ans++;
    }
  }
  rep(i,n)
  {
    ans += a[i]/2;
    a[i] %= 2;
  }
  cout << ans << endl;
}