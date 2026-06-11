#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
int main()
{
   int n,k,x,y;
   cin>>n>>k>>x>>y;
   if(n<k)
   {
      cout<<n*x<<nl;
   }
   else
   {
      if(n==k)
      {
         cout<<n*x<<nl;
      }
      else
      {
         cout<<((k*x)+((n-k)*y))<<nl;
      }
   }
    return 0;
}
