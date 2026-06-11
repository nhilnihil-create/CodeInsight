#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ll n,k,x=-2,y=2000000,m;map<ll,ll>ml;
    cin>>n>>m;
    vector<pair<ll,ll>>v;
    for(int i=1;i<=m;i++){
        ll a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v[i].first==1)ml[v[i].second]=1;
        else if(v[i].second==n&&ml[v[i].first]){
            cout<<"POSSIBLE";return 0;
        }
    }
    cout<<"IMPOSSIBLE";

    return 0;
}
