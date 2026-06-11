#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<int>())
using namespace std;
int main()
{
  speed_up;
  ll n, x, i, sum, d, b, cnt = 0;
  cin>>n>>x;
  ll a[n];
  for(i = 0; i<n; i++)
  {
      cin>>a[i];
  }
  for(i = 0; i<n-1; i++)
  {
      sum = a[i] + a[i+1];
      if(sum>x)
      {
         cnt += sum - x;
         d = a[i+1] -sum + x;
         if(d<0) d = 0;
         a[i+1] = d;
      }
  }
  /*for(i = 0; i<n; i++)
  {
      cout<<a[i]<<endl;
  }*/
  //cout<<endl;
  cout<<cnt<<endl;

  return 0;
}

