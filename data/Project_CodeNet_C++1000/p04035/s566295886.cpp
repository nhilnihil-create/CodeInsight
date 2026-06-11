#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  int n;cin>>n;
  ll l,a[n];
  cin>>l;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  int f=0,tem;
  for(int i=1;i<=n-1;i++)
  {
    if((a[i]+a[i+1])>=l)
    { f=1;tem=i;break;}
  }
  if(f==0)
    cout<<"Impossible\n";
  else
  {
      cout<<"Possible\n";
      for(int i=1;i<tem;i++)
        cout<<i<<endl;
      for(int i=n-1;i>tem;i--)
        cout<<i<<endl;
      cout<<tem<<endl;
  }
}
