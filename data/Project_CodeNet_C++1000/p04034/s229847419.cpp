#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, m;
    cin>>n>>m;
    pair<bool , ll> * a = new pair<bool , ll>[n];
    a[0].first = true;
    a[0].second = 1;
    for(int i=1;i<n;i++)
    {
        a[i].first = false;
        a[i].second = 1;
    }
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        if( a[x].first  )
        {
            a[y].first = true;

        }
        a[x].second --;
        a[y].second ++;
        if( a[x].first && a[x].second <=0)
            a[x].first = false;
    }
    ll ans =0;
    for(int i=0;i<n;i++)
    {
        if( a[i].first == true && a[i].second >0)
            ans++;
    }
    cout<<ans;
}