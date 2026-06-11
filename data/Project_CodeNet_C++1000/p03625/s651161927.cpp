#include <bits/stdc++.h>
using namespace std;
map<long,long>mp;
int main()
{
    long i,j,t,a,b,n,c,y,m,prev,sum,ans=1;
    t=1;
    // cin>>t;
    while(t--)
    {
       string s;
       cin>>n;
       long arr[n];
       for(i=0;i<n;i++)
       {
           cin>>arr[i];
           mp[arr[i]]++;
       }
       m=0;
       bool flag=false;
       for(auto x:mp)
       {
           if(x.second>=4)
           {
               m=4;
           }
           else if(x.second>=2)m+=2;
       }
       if(m<4)
       {
           cout<<0;
           return 0;
       }
       sort(arr,arr+n);
       reverse(arr,arr+n);
       long count=1;
       long times=0;
       for(i=1;i<n;i++)
       {
           if(arr[i-1]==arr[i])
           {
               count++;
           }
          
           if(count==2)
           {
               ans*=arr[i];
               times++;
               count=1;
               i++;
           }
           if(times==2)break;
       }
       cout<<ans;
    }
}