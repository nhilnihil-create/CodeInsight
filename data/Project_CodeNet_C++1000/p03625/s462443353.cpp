#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    map<ll,ll, greater<ll>>mp;
    for(ll i=0; i<n; i++ )
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    ll c=0;
    ll ar=1;
    ll f=0;
    for(auto it=mp.begin(); it!=mp.end(); ++it)
    {
        ll s=it->second;
        if(c==0)
        {
            if(s>=4)
            {
                cout<<it->first*it->first<<endl;
                f=1;
                break;
            }
        }
        if(s>=2)
        {
            ar=ar*it->first;
            c++;
            if(c==2)
            {
                break;
            }
        }
    }
    if(c!=2&&f==0)
    {
        cout<<0<<endl;
    }
    else if(c==2&&f==0)
    {
        cout<<ar<<endl;
    }

}
