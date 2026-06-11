#include <bits/stdc++.h>

using namespace std;

int main()
{   long long int n,s=1,mod=1e9+7;//100000000+7
  cin>>n;
   for(long long int i=1;i<=n;i++)
   {
         s=s*(1*i);
       s=s%mod;
   }
   cout<<s<<"\n";
    return 0;
}
