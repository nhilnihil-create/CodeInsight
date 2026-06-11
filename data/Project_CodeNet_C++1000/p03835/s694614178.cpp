#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long  i,j,s,k,r=0;
    cin>>k>>s;
    for(i=0;i<=k;i++)
    {
      for(j=0;j<=k;j++)
      {
        if(s-i-j<=k && s-i-j>=0) r++;
      }
    }
    cout<<r;
  return 0;
}
