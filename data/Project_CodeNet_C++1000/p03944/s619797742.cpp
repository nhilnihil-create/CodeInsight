#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll w , h,n;
    cin>>w>>h>>n;
    ll lx = 0  , ux = w , ly = 0 , uy = h;
    for(int i=0;i<n;i++)
    {
        ll x,y,a;
        cin>>x>>y>>a;
        if( a == 1)
        {
            lx = max( lx , x);
        }
        if( a== 2)
            ux = min( ux , x);
        if( a== 3)
            ly = max( ly , y);
        if( a== 4 )
        {
            uy = min( uy , y);
        }
    }
    ll ans =0;
    if( lx >= ux || ly>= uy )
    {
        cout<<0;
    } else
    {
        ans =( uy - ly )* (ux - lx );
        cout<<ans;
    }
}