#include<bits/stdc++.h>
using namespace std;
int fa1[200009];
int fa2[200009];
int findset1(int u)
{
    return fa1[u]==u?u:fa1[u]=findset1(fa1[u]);
}
int findset2(int u)
{
   return fa2[u]==u?u:fa2[u]=findset2(fa2[u]);
}
int main()
{
    int n,k,r;
    cin>>n>>k>>r;
    for(int i=1;i<=n;i++)
    {
        fa1[i]=i;
        fa2[i]=i;
    }
    int u,v;
    for(int i=1;i<=k;i++)
    {
        cin>>u>>v;
        int fu=findset1(u);
        int fv=findset1(v);
        if(fu!=fv)
        {
            fa1[fu]=fv;
        }
    }
    for(int i=1;i<=r;i++)
    {
        cin>>u>>v;
        int fu=findset2(u);
        int fv=findset2(v);
        if(fu!=fv)
        {
            fa2[fu]=fv;
        }
    }
    map<pair<int,int>,int>mp;
    for(int i=1;i<=n;i++)
    {
        findset1(i);
        findset2(i);
    }
    for(int i=1;i<=n;i++)
    {
        mp[make_pair(fa1[i],fa2[i])]++;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<mp[make_pair(fa1[i],fa2[i])]<<" ";
    }

}
