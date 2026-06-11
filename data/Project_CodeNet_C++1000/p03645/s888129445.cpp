#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int main()
{
    map<ll,bool>vis;
    bool valid=0;
    ll n,m;
    cin>>n>>m;
    while(m--)
    {
        ll a,b;
        cin>>a>>b;
        if(a==1)
        {
            if(vis[b])
                valid=1;
            vis[b]=1;
        }
        else if(b==n)
        {
            if(vis[a])
            {
                valid=1;
            }
            vis[a]=1;
        }
    }
    if(valid)
        cout<<"POSSIBLE"<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
