#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N=2e5+10;
const int maxn=1e6;
int fa1[N],fa2[N];
int find1(int x)
{
    if(fa1[x]!=x) fa1[x]=find1(fa1[x]);
    return fa1[x];
}
int find2(int x)
{
    if(fa2[x]!=x) fa2[x]=find2(fa2[x]);
    return fa2[x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k,l,x,y;
    cin>>n>>k>>l;
    for(int i=1;i<=n;i++) fa1[i]=i,fa2[i]=i;
    for(int i=1;i<=k;i++)
    {
        cin>>x>>y;
        int r1=find1(x);
        int r2=find1(y);
        if(r1!=r2) fa1[r2]=r1;
    }
    for(int i=1;i<=l;i++)
    {
        cin>>x>>y;
        int r1=find2(x);
        int r2=find2(y);
        if(r1!=r2) fa2[r2]=r1;
    }
    for(int i=1;i<=n;i++)
    {
        find1(i);
        find2(i);
    }
    map<pair<int,int>,int>f;
    for(int i=1;i<=n;i++)
    {
        f[make_pair(fa1[i],fa2[i])]++;
    }
    for(int i=1;i<=n;i++) cout<<f[make_pair(fa1[i],fa2[i])]<<" ";
    return 0;
}