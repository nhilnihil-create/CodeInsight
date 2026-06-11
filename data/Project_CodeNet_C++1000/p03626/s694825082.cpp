#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;cin>>n;
    string s1,s2;cin>>s1>>s2;
    vector<ll>v;
    for(ll i=0;i<s1.length();i++)
    {
        if(s1[i]==s2[i]){
            v.push_back(2);        /// col or (1 2)
        }
        else
        {
            v.push_back(1);     ///row or (2 1)
            i++;
        }
    }
//    for(ll i=0;i<v.size();i++)cout<<v[i]<<" ";
    ll mod=1000000007;
    ll ans=0;
    if(v[0]==1)ans=6;
    else ans=3;
    for(ll i=1;i<v.size();i++)
    {
        if(v[i]==2)
        {
            if(v[i-1]==2)ans=(ans*2)%mod;
        }
        else
        {
            if(v[i-1]==2)ans=(ans*2)%mod;
            else ans=(ans*3)%mod;

        }
    }
    cout<<ans<<endl;
}
