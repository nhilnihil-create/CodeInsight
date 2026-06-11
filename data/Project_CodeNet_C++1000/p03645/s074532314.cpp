///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll a[m],b[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i]>>b[i];
    }
    vector<vector<ll> >v(n+1);
    for(int i=0;i<m;i++)
    {
        v[a[i]].push_back(b[i]);
    }
   /* for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }*/
    bool f=0;
    //cout<<v[1].size();
    for(int i=0;i<v[1].size();i++)
    {
        if(count(v[v[1][i]].begin(),v[v[1][i]].end(),n))
        {
            f=1;break;
        }
    }
    if(f==1)
        cout<<"POSSIBLE"<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
}