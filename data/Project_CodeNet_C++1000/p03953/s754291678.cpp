#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,m,i,j,x,p[N],a[N],t,q[N];
long long nk,v;
bool vis[N];
int read(){
	char c=getchar();int k=0,p=0;
	for (;c<48||c>57;c=getchar()) if (c=='-') p=1;
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;
	return p?-k:k;
}
int main(){
	for (n=read(),i=1;i<=n;i++) p[i]=read();
	m=read();scanf("%lld",&nk);
	for (i=1;i<n;i++) a[i]=i;
	for (;m--;){int x=read();swap(a[x-1],a[x]);}
	for (i=1;i<n;i++) if (!vis[i]){
		for (x=i,t=0;!vis[x];x=a[x]) vis[x]=1,q[t++]=x;
		for (j=0;j<t;j++) a[q[j]]=q[(j+nk)%t];
	}
	for (v=p[1],i=1;i<=n;i++)
		printf("%lld.0\n",v),v+=p[a[i]+1]-p[a[i]];
}