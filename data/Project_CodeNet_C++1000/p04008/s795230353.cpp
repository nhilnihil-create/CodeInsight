#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100010;
int n,k,ans,tt;
int head[N],to[N],nxt[N],a[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline int dfs(int x) {
    int d=0;
    for(int i=head[x];i;i=nxt[i])
	d=max(d,dfs(to[i])+1);
    if(d==k-1&&a[x]!=1) ++ans,d=-1;
    return d;
}
int main() {
    cin>>n>>k,a[1]=1;
    if(gi()!=1) ++ans;
    for(int i=2,x;i<=n;i++)
	to[++tt]=i,nxt[tt]=head[x=a[i]=gi()],head[x]=tt;
    dfs(1);
    cout<<ans;
    return 0;
}