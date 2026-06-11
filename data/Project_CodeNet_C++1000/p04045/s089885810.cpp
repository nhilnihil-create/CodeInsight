#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll>arr(k);
    vector<ll> val(10,0);
    for(ll i=0;i<k;i++)
    {
        cin >> arr[i];
        val[arr[i]]++;

    }
    for(ll i=n;i<10*n;i++)
    {
        ll temp=i;
        map<ll,ll> mp;
        while(temp)
        {
            ll mod=temp%10;
            mp[mod]++;
            temp/=10;

        }
        ll flag=1;
        for(auto x:mp)
        {
            if(x.second>0)
            {
                if(val[x.first]!=0)
                {
                    flag=-1;
                    
                }
            }
        }
        if(flag==1)
        {
            cout <<i;
            break;
        }


    }
}
