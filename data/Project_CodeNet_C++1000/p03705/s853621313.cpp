#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
   ll n,a,b;
   cin>>n>>a>>b;
   ll ans =0;
   if( n>= 2) {
       ll temp1 = (n - 2) * b + b + a;
       ll temp2 = (n - 2) * a + a + b;
       ans = temp1 - temp2 + 1;
       if( a> b)
           ans =0;
   } else
   {
       if( n==1 && a!= b)
       {
           ans =0;
       }
       else ans =1;
   }
   cout<<ans;

}