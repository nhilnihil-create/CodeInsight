#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 100000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
vector<int> v[MN+5];
int n,K,a[MN+5],ans,d[MN+5];
void dfs(int x)
{
    d[x]=0;
    for(int i=0;i<v[x].size();++i)
    {
        dfs(v[x][i]);
        if(d[v[x][i]]+1+(x!=1)>K) ++ans;
        else d[x]=max(d[x],d[v[x][i]]+1);
    }
}
int main()
{
    n=read();K=read();
    for(int i=1;i<=n;++i) a[i]=read();
    ans=(a[1]!=1);
    for(int i=2;i<=n;++i) v[a[i]].push_back(i);
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
