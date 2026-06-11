#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
using namespace std;
int main()
{
  speed_up;
  ll a[100000] = {};
  ll n, flag = 0, ans = 1, i;
  ll m = 1000000000 + 7;
  cin>>n;
  ll b[n];
  for(auto &x: b)
  {
      cin>>x;
      a[x]++;
      if(a[x]>2) flag++;
  }
  if(flag > 0)
  {
      cout<<0<<endl;
      return 0;
  }
  if(n%2 != 0 && a[0]>1)
  {
      cout<<0<<endl;
      return 0;
  }
    for(i = 0; i<n/2; i++)
    {
      ans*=2;
      ans%=m;
    }
    cout<<ans<<endl;

      return 0;
}
