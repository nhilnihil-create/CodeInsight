#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool condition( ll a , ll b , ll c)
{
    return !(a % 2 || b % 2 || c % 2);
}
int main()
{
    ll a , b, c;
    cin>>a>>b>>c;
    ll ans =0;
    while( condition(a,b,c))
    {
        ll tempa = (b+c)/2;
        ll tempb = (a+c)/2;
        ll tempc = ( a+b)/2;

        if( tempa== a && tempb == b && tempc ==c)
        {
            cout<<-1;
            return 0;
        }
        ans++;
        a = tempa;
        b = tempb;
        c = tempc;
     }
    cout<<ans;
}