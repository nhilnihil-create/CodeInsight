#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,t,a,b,n,c,y,d,m,prev,sum,ans;
    t=1;
    // cin>>t;
    while(t--)
    {
       cin>>a>>b>>c>>d;
      cout<<max(min(b,d)-max(a,c),0);
    }
}