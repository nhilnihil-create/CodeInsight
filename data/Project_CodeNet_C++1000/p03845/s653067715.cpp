#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,c,n;
    cin >> n;
    ll ara[n+10],sum = 0 ;
    for(ll i=1; i<=n; i++)
    {
        cin >> ara[i];
        sum += ara[i];
    }
    ll m;
    cin >> m;
    for(ll i=1; i<=m; i++)
    {
        ll x,y;
        cin >> x >> y;
        ll temp = sum ;
        temp -= ara[x] ;
        temp += y;
        cout << temp << endl;
    }


}
