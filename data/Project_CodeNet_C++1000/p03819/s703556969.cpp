#include <bits/stdc++.h>
using namespace std;
int n,m,s[500005],l[500005],r[500005],ans;vector<int>v[500005];
void add(int x,int v){for(;x<=m;x+=x&-x) s[x]+=v;}
int que(int x){int r=0;for(;x;x-=x&-x) r+=s[x];return r;}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]),v[r[i]-l[i]+1].push_back(i);
    for(int i=1;i<=m;i++,ans=0)
    {
        for(int j=0;j<v[i].size();j++) add(l[v[i][j]],1),add(r[v[i][j]]+1,-1);
        for(int j=i;j<=m;j+=i) ans+=que(j);
        n-=v[i].size();printf("%d\n",ans+n);
    }
}