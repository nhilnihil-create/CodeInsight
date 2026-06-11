#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
  int w,a,b;
  cin>>w>>a>>b;
  if(a>b)
  {
      int temp=a;
      a=b;
      b=temp;
  }
  if(w+a>=b)
    cout<<0<<endl;
  else
    cout<<abs(w+a-b)<<endl;
}