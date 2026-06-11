#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int fa1[N],fa2[N];
map<pair<int,int>,int> mp;
int get1(int x)
{
    if(x==fa1[x])
        return x;
    else
        return fa1[x]=get1(fa1[x]);
}
int get2(int x)
{
    if(x==fa2[x])
        return x;
    return fa2[x]=get2(fa2[x]);
}
void merge1(int x,int y)
{
    int fx=get1(x),fy=get1(y);
    if(fx!=fy)
        fa1[fx]=fy;
}
void merge2(int x,int y)
{
    int fx=get2(x),fy=get2(y);
    if(fx!=fy)
        fa2[fx]=fy;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        fa1[i]=fa2[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        merge1(x,y);
    }
    for(int i=1;i<=k;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        merge2(x,y);
    }
    for(int i=1;i<=n;i++)
        mp[make_pair(get1(i),get2(i))]++;
    for(int i=1;i<=n;i++)
        printf("%d%c",mp[make_pair(get1(i),get2(i))],i!=n?' ':'\n');
    return 0;
}