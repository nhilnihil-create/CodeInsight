#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,t;
  cin>>n>>t;
  int a[n];
  int i;
  for(i=0;i<n;i++)
  cin>>a[i];
  long long int ans=t,d=t;
  for(i=1;i<n;i++)
  {
    if(d>=a[i])
    {
      ans+=a[i]-a[i-1];
      d=a[i]+t;
    }
    else
    {
      ans+=d-a[i-1];
      d=a[i]+t;
    }
  }
  cout<<ans<<endl;
  return 0;
}