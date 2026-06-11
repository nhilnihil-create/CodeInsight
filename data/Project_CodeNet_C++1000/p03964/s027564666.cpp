#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,T=1,A=1,t,a,ans,x,y,r;
    cin>>n;
    while(n--)
    {
        cin>>t>>a;
        x=(T+t-1)/t;
        y=(A+a-1)/a;
        r=max(x,y);
        T=t*r;
        A=a*r;
    }
    ans=A+T;
    cout<<ans;
    return 0;
}

