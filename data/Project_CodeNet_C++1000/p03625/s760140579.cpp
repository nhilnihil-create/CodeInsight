#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  long long ara[n+5];
  for(int i=0;i<n;i++)cin>>ara[i];
  sort(ara,ara+n);
  long long h=-1,w=-1;
  for(int i=n-1;i>=1;i--)
  {
    if(h==-1 && ara[i]==ara[i-1])h=ara[i],i--;
    else if(h!=-1 && ara[i]==ara[i-1])
    {
      w=ara[i];
      break;
    }
  }
  if(h!=-1 && w!=-1)cout<<h*w<<endl;
  else cout<<0<<endl;
}
