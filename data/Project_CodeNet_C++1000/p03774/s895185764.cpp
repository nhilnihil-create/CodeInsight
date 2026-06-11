#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,d,min=LONG_MAX,index=0;
    cin>>n>>m;
    vector<pair<int,int>>v,v1;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        v1.push_back(make_pair(x,y));
    }
    for(int i=0;i<n;i++)
    {
        d=0,min=LONG_MAX;
        for(int j=0;j<m;j++)
        {
            d=abs(v[i].first-v1[j].first)+abs(v[i].second-v1[j].second);
            if(d<min)
            {
                min=d;
                index=j+1;
            }
        }
        cout<<index<<endl;
    }
    return 0;
}