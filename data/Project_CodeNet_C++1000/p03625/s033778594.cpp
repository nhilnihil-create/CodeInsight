#include<bits/stdc++.h>
#define ll long long int
using namespace std;

map<ll,ll>l2;

int main()
{
    ll n,x=0,y;
    cin>>n;
    ll l1[n+1];map<ll,ll>m;
    vector<ll>v;
    vector<ll>v2;
    for(int i=1;i<=n;i++){
        cin>>l1[i];l2[l1[i]]++;
        if(l2[l1[i]]==2)v.push_back(l1[i]);
        else if(l2[l1[i]]==4)v2.push_back(l1[i]);
    }
    sort(v.begin(),v.end(),greater<int>());
    sort(v2.begin(),v2.end(),greater<int>());
    if(v2.size()>=1)x=max(x,(ll)(v2[0]*v2[0]));
    if(v.size()>=2)x=max(x,(ll)(v[0]*v[1]));
    cout<<x<<endl;

    return 0;
}
