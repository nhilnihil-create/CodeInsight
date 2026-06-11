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
       if(n%3==0 || m%3==0 ||(n+m)%3==0)
       cout<<"Possible";
       else cout<<"Impossible";
      
    }
}