#include<bits/stdc++.h>
#define ll long long int
using namespace std;

map<ll,ll>l2;

int main()
{
    ll n;
    cin>>n;
    ll s=0;vector<ll>v;
    for(int i = 1; i<=n;i++){
        ll a,b;
        cin>>a;
        if(!l2[a])v.push_back(a);
        l2[a]++;
    }
    for(int i=0;i<v.size();i++){
        if(l2[v[i]]&1)s++;
    }
    cout<<s;

    return 0;
}
