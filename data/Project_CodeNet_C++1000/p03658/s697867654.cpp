#include <bits/stdc++.h>
using namespace std;
#define max 200009
map<long,long>mp;

int main()
{
    long i,j,t,a,b,n,c,temp,m;
    t=1;
    // cin>>t;
    while(t--)
    {
       cin>>n>>m;
       long arr[n+1];
       for(i=0;i<n;i++)
       {
           cin>>arr[i];
           
       }
       sort(arr,arr+n);
       reverse(arr,arr+n);
       cout<<accumulate(arr,arr+m,0LL);
      
    }
}