#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[60];
pair<int,int> b[60];

#define INF 1000000000

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;cin>>n>>m;

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

    int ans[60];

    for(int i=0;i<n;i++)
    {
        int dis=INF;
        for(int j=0;j<m;j++)
        {
            int d=abs(a[i].first-b[j].first)+abs(a[i].second-b[j].second);
            if(dis>d)
            {
                dis=d;
                ans[i]=j+1;
            }
        }
    }

    for(int i=0;i<n;i++)cout<<ans[i]<<"\n";

    return 0;
}
