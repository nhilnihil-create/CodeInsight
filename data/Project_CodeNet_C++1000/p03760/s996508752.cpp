#include<bits/stdc++.h>
using namespace std;
int main()
{
  string a,b;
  int i;
  cin>>a>>b;
  if(a.size()==b.size())
  {
    for(i=0; i<a.size(); i++)
    {
      cout<<a[i]<<b[i];
    }
  }
  else
    if(a.size()>b.size())
    {
      for(i=0; i<b.size(); i++)
      {
        cout<<a[i]<<b[i];
      }
      cout<<a[i];
    }
  else
  {
     for(i=0; i<a.size(); i++)
      {
        cout<<a[i]<<b[i];
      }
      cout<<b[i];
  }
    
}
