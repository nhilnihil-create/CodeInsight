#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
   op;
   int n,k,sum=0;
   cin>>n>>k;
   int a[n];
   for(int i=0;i<n;i++)
   {
      cin>>a[i];
   }
   sort(a,a+n,greater<int>());
   for(int i=0;i<k;i++)
   {
      sum+=a[i];
   }
   cout<<sum<<nl;
   return 0;
}
