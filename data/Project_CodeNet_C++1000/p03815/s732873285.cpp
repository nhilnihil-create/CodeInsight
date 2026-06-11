#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long n,ans=0,x;
  cin>>n;
  x=ceil(n/11.0);
  ans=x*2;
  if(x*11-n>=5)
    ans--;
  cout<<ans<<endl;
  return 0;
}