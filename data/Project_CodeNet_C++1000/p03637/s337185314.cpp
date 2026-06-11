#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    long i,j,t,a,b,n,c,temp,m;
    t=1;
    // cin>>t;
    while(t--)
    {
       cin>>n;
       temp=0;
       long arr[n];
       long e=0;
       for(i=0;i<n;i++)
       {
         cin>>arr[i];
         if(arr[i]%4==0)temp++;
         else if(arr[i]%2==0)e++;
       }
       e=e/2;
       temp=temp+e;
       if(temp>=n/2)cout<<"Yes";
       else cout<<"No";
      
    }
}