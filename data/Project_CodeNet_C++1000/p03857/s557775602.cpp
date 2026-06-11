#include<iostream>
#include<map>
using namespace std;
const int maxn=200005;
int root1[maxn],root2[maxn];
map<pair<int,int>,int> mp;
int ufind(int x,int *root)
{
    if(root[x]==x)
    {
        return x;
    }else
        return root[x]=ufind(root[x],root);
}
void umerge(int p,int q,int*root)
{
    int rp=ufind(p,root);
    int rq=ufind(q,root);
    if(rp!=rq)
    {
        root[rq]=rp;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n,k,l,x,y;
    cin>>n>>k>>l;
    for(int i=1;i<=n;++i)
    {
        root1[i]=i;
        root2[i]=i;
    }
    for(int i=1;i<=k;++i)
    {
        cin>>x>>y;
        umerge(x,y,root1);
    }
    for(int i=1;i<=l;++i)
    {
        cin>>x>>y;
        umerge(x,y,root2);
    }
   for(int i=1;i<=n;++i)
    {
        ufind(i,root1);
        ufind(i,root2);
    }
    for(int i=1;i<=n;++i)
    {
        mp[make_pair(root1[i],root2[i])]++;
    }
    for(int i=1;i<=n;++i)
    {
        cout<<mp[make_pair(root1[i],root2[i])]<<" ";
    }cout<<endl;
    return 0;
}