#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define p pair<int,int>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define pi acos(-1)

int main()
{
    fast;
    ll n;
    cin>>n;
    vector<ll>vec(n);
    map<ll,ll>mp;
    for(auto &i:vec)
    {
        cin>>i;
        mp[i]++;
    }
    vector<ll> ans;
    map<ll,ll>:: iterator it,it1;
    it=mp.end();
    it--;
    it1=mp.begin();
    it1--;
    ll count=0;
    for(;it!=it1;it--)
    {
        if(it->ss>=4)
        {
            count+=4;
            ans.pb(it->ff);
        }
        else if(it->ss>=2)
        {
            count+=2;
            ans.pb(it->ff);
        }
        if(count==4)break;

    }
    if(count<4)cout<<0<<endl;
    else
    {
        if(ans.size()==1)cout<<1LL*ans[0]*ans[0]<<endl;
        else cout<<1LL*ans[0]*ans[1]<<endl;
    }
}

