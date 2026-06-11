#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;  cin>>n;
  int a[n];
  int hasha[n]={0};
  for(int i=0;i<n;i++)  hasha[i]=0;
  long long int ans=0,mod=1000000007;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    ++hasha[a[i]];
    if(hasha[a[i]]>2)
    ans=-1;
  }
  
  if((n%2 && hasha[0]!=1) || (n%2==0 && hasha[0]!=0) || ans==-1)
  {
    cout<<"0";
  }
  else
  {
    for(int i=1;i<n;i++)
    {
      if(!(hasha[i]==0 || (hasha[i]==2)))
      {
        ans = -1;
        break;
      }
    }
    if(ans!=-1)
    {
      n=n>>1;ans=1;
      for(int i=0;i<n;i++)
      {
        ans*=2;
        ans%=mod;
      }
      cout<<ans;
    }
    else if(ans==-1)
    cout<<"0";
  }
  
  return 0;
}