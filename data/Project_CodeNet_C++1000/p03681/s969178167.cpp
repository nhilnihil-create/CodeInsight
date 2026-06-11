#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    long i,j,t,a,b,n,temp;
    t=1;
    // cin>>t;
    while(t--)
    {
       cin>>a>>b;
       if(abs(a-b)>1)cout<<"0";
       else
       {
           if(a==b)
           {
               temp=1;
               while(a>0)
               {
                   temp=(temp*a)%mod;
                   a--;
               }
               temp=(temp*temp)%mod;
               cout<<(temp*2)%mod;
           }
           else 
           {
               temp=min(a,b);
               long ans=1;
               while(temp>0)
               {
                   ans=(temp*ans)%mod;
                   temp--;
               }
               cout<<(((ans*ans)%mod)*max(a,b))%mod;
           }
           
       }
        
    }
}