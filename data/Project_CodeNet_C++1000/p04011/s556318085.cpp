#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t=1;
    while(t--)
    {
        ll n,k,x,y;
        cin>>n>>k>>x>>y;
        ll cnt=min(k,n);
        ll r=max(0LL,n-cnt);
        cout<<(cnt*x+r*y)<<endl;
    }
}
