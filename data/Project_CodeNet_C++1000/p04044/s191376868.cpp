#include <bits/stdc++.h>
#define ll long long int


using namespace std;

int main()
{
    ll t,n,item,temp,a,b,c,x,y,z,sum,flag;
    string s,s1,s2;
    vector<ll>v;
    vector<string>vs;
    map<ll,ll>mp;
   vector< pair<char,ll> >p;
    cin>>n>>a;
    for(ll i=0;i<n;i++)
    {
        cin>>s;
        p.push_back(make_pair(s[0],i));
        vs.push_back(s);

    }
    sort(vs.begin(),vs.end());
string ans="";
    for(ll i=0;i<n;i++)
    {

        ans+=vs[i];
    }
    cout<<ans<<endl;

    return 0;
}
