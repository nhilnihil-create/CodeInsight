#include <bits/stdc++.h>
using namespace std;
map<long,long>mp;
int main()
{
    long i,j,t,a,b,n,c,y,m,prev,sum,ans=1,count,k;
    t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(i=0;i<n;i++)
        {
            cin>>a>>b;
            ans+=b-a+1;
        }
        cout<<ans;
    }
}