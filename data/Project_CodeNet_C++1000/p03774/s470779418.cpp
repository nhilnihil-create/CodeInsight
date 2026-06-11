#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

using ll = long long;
#define INF 1000000000000000000

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;cin>>n>>m;

    vector<pair<int,int>> a(n),b(m);

    for(int i=0;i<n;i++)
    {
        int ia,ib;cin>>ia>>ib;
        a[i]=make_pair(ia,ib);
    }

    for(int i=0;i<m;i++)
    {
        int ic,id;cin>>ic>>id;
        b[i]=make_pair(ic,id);
    }

    for(int i=0;i<n;i++)
    {
        int ans=0;
        ll mindist=INF;
        for(int j=0;j<m;j++)
        {
            ll dist=abs(a[i].fi-b[j].fi)+abs(a[i].se-b[j].se);
            if(mindist>dist)
            {
                mindist=dist;
                ans=j+1;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
