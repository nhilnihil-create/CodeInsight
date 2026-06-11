#include<bits/stdc++.h>
using namespace std;
#define RI register int
int read() {
    int q=0;char ch=' ';
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
    return q;
}
const int N=100005;
int n,tot,h[N],ne[N],to[N],st[N],f[N];
void add(int x,int y) {to[++tot]=y,ne[tot]=h[x],h[x]=tot;}
bool cmp(int x,int y) {return x>y;}
void dfs(int x) {
    int top=0;
    for(RI i=h[x];i;i=ne[i]) dfs(to[i]);
    for(RI i=h[x];i;i=ne[i]) st[++top]=f[to[i]];
    sort(st+1,st+1+top,cmp);
    for(RI i=1;i<=top;++i) f[x]=max(f[x],st[i]+i);
}
int main()
{
    int x;n=read();
    for(RI i=2;i<=n;++i) x=read(),add(x,i);
    dfs(1),printf("%d\n",f[1]);
    return 0;
}