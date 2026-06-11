#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

char buf[1<<15],*fs,*ft;
inline char getc() { return (ft==fs&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),ft==fs))?0:*fs++; }
template<typename T>inline void read(T &x)
{
    x=0;
    T f=1, ch=getchar();
    while (!isdigit(ch) && ch^'-') ch=getchar();
    if (ch=='-') f=-1, ch=getchar();
    while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
    x*=f;
}

int ver[maxn<<1],Next[maxn<<1],head[maxn],len,deg[maxn];
inline void add(int x,int y)
{
	ver[++len]=y,Next[len]=head[x],head[x]=len;
}

ll A[maxn];
bool flag=1;
inline void dfs(int x,int fa)
{
	ll sum=0,maxpart=0; int o=0;
	for (int i=head[x]; i; i=Next[i])
	{
		int y=ver[i];
		if (y==fa) continue;
		++o;
		dfs(y,x);
		sum+=A[y];
		maxpart=max(maxpart,A[y]);
	}
	if (!o) return ;
	ll a=sum-A[x],b=(A[x]<<1)-sum;
	if (a<0 || b<0 || a>min(sum-maxpart,sum>>1) || (fa==-1 && b)) flag=0;
	A[x]=b;
}

int main()
{
	int n;read(n);
	for (int i=1; i<=n; ++i) read(A[i]);
	for (int i=1,a,b; i<n; ++i) read(a),read(b),add(a,b),add(b,a),++deg[a],++deg[b];
	int root=0;
	for (int i=1; i<=n; ++i)
		if (deg[i]>1) { root=i; break; }
	if (root) dfs(root,-1);
	else flag=(A[1]==A[2]);
	puts(flag?"YES":"NO");
	return 0;
}