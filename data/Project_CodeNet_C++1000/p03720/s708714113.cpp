#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    ll n,k;
    cin>>n>>k;
    vector<vector<ll>>v(n);
    for(int i=0;i<k;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        v[y].push_back(x);
        v[x].push_back(y);
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i].size()<<endl;
    }

}
