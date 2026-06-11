#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
   op;
   int n,i=1;
   cin>>n;
   while(i*2<=n)
   {
      i*=2;
   }
   cout<<i<<nl;
   return 0;
}
