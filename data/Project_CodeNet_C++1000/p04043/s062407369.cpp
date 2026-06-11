#include <bits/stdc++.h>
#define ll long long int


using namespace std;

int main()
{
    ll t,n,item,temp,a,b,c,x,y,z,sum,flag;
    vector<ll>v;
    map<ll,ll>mp;
    cin>>a>>b>>c;
    mp[a]++;
    mp[b]++;
    mp[c]++;
    if(mp[5]==2 && mp[7]==1)
        cout<<"YES"<<endl;
        else
    cout<<"NO"<<endl;

    return 0;
}
