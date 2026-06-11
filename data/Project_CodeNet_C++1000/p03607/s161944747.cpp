#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    set<ll> data;

    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        if( data.find(x) != data.end() )
        {
            data.erase( x) ;
        } else data.insert(x);
    }
    cout<<data.size();
}