#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ll n , m;
    cin>>n>>m;
    pair<ll , ll> *student = new pair<ll, ll> [n];
    pair<ll , ll> *cpoint = new pair<ll, ll> [m];
    for(ll i=0;i<n;i++)
    {
         cin>>student[i].first >>student[i].second;
    }
    for(ll i=0;i<m;i++)
    {
        cin>>cpoint[i].first >>cpoint[i].second;
    }
    for(int i=0;i<n;i++)
    {
        ll ans =0;
        ll minD = LLONG_MAX;
        for(int j=0;j<m;j++)
        {
            ll temp = abs( student[i].first - cpoint[j].first) +  abs( student[i].second - cpoint[j].second);

            if( temp < minD)
            {
                minD = temp;
                ans = j;

            }
        }
        cout<<ans+1<<endl;
    }

}