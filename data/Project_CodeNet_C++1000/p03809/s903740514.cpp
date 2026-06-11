#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100010;
int tt;
int head[N],a[N],to[N*2],nxt[N*2],in[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') ch=getchar(),o=-1;
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline void dfs(int x,int fa) {
    if(in[x]==1) return;
    int Mx=0;
    long long sum=0;
    for(int i=head[x];i;i=nxt[i]) {
	int y=to[i];
	if(y!=fa) {
	    dfs(y,x),sum+=a[y];
	    Mx=max(Mx,a[y]);
	}
    }
    if(sum<a[x]||sum>a[x]*2||Mx>a[x])
	puts("NO"),exit(0);
    a[x]-=sum-a[x];
}
int main() {
    int n,rt=1;
    cin>>n;
    if(n==2) return puts(gi()==gi()?"YES":"NO"),0;
    for(int i=1;i<=n;i++) a[i]=gi();
    for(int i=1;i<n;i++) {
	int x=gi(),y=gi();
	++in[x],++in[y];
	to[++tt]=y,nxt[tt]=head[x],head[x]=tt;
	to[++tt]=x,nxt[tt]=head[y],head[y]=tt;
    }
    for(int i=1;i<=n;i++) if(in[i]>1) rt=i;
    dfs(rt,0);
    puts(a[rt]?"NO":"YES");
    return 0;
}