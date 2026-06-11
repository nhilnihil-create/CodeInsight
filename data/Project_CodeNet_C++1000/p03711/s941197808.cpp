#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll x,y;
    cin>>x>>y;
    vector<vector<ll>>v={{1,3,5,7,8,10,12},{4,6,9,11},{2}};
    ll a,b;
    for(ll j=0;j<v.size();j++)
    {
        for(ll i=0;i<v[j].size();i++)
        {
            if(v[j][i]==x) a=j;
            if(v[j][i]==y) b=j;
        }
    }
    if(a==b)
        cout<<"Yes";
  else
    cout<<"No";
}
