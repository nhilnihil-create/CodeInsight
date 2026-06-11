///HELLO THERE~!
///CREATED BY MD SADMAN MEHEDI SIVAN(IUT CSE[SWE'19])

#include<bits/stdc++.h>
using namespace std;

#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define READ            freopen("input.txt","r",stdin);
#define WRITE           freopen("red.txt","w",stdout);

using ll=long long;
using ull=unsigned long long;
const double pi = 2*acos(0.0);
const long long MX = 2e5+7;
int main()
{

    ll n;
    cin>>n;

    map<ll,ll>mp;

    ll count=0;

    ll a[n+1];

    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
        if(mp[a[i]]==0)
        {
            mp[a[i]]++;
            count++;
        }
        else
        {
            mp[a[i]]=0;
            count--;
        }
    }

    cout<<count;
}
