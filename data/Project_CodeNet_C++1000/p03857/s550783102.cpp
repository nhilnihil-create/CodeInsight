#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=2e5+10;
int F1[maxn],F2[maxn];
int findset1(int x)
{
    if(F1[x]==x) return x;
    return F1[x]=findset1(F1[x]);
}
int findset2(int x)
{
    if(F2[x]==x) return x;
    return F2[x]=findset2(F2[x]);
}
int main()
{
    int n,k,l;
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1;i<=n;i++)
    {
        F1[i]=i;
        F2[i]=i;
    }
    for(int i=1;i<=k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int fx=findset1(x);
        int fy=findset1(y);
        if(fx!=fy)
            F1[fx]=fy;
    }
    for(int i=1;i<=l;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int fx=findset2(x);
        int fy=findset2(y);
        if(fx!=fy)
            F2[fx]=fy;
    }
    for(int i=1;i<=n;i++)
    {
        findset1(i);findset2(i);
    }
    map<pair<int ,int >,int >mp;
    for(int i=1;i<=n;i++)
    {
        mp[make_pair(F1[i],F2[i])]++;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<mp[make_pair(F1[i],F2[i])]<<" ";
    }
    cout<<endl;
    return 0;
}
