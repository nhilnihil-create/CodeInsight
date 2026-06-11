#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int n,k,a[N],dis[N],ans=0;
vector<int> E[N];
void dfs(int u) {
    dis[u]=0;
    for(int v:E[u]) dfs(v),dis[u]=max(dis[u],dis[v]+1);
    if(dis[u]==k-1&&a[u]!=1) dis[u]=-1,ans++;
}
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) a[i]=gi();
    if(a[1]!=1) ans++,a[1]=1;
    for(int i=2;i<=n;i++) E[a[i]].push_back(i);
    dfs(1);printf("%d\n",ans);
    return 0;
}
//orzgzy
//鸡贼明年进队超稳
