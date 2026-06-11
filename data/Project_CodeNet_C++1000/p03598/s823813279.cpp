#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

   ll n,k;
   cin>>n>>k;
   ll arr[n+5]={0};
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   ll dis=0;
   for(int i=0;i<n;i++)
   {
       ll x=min(arr[i],k-arr[i]);
       dis+=2*x;
   }
   cout<<dis<<endl;
}
