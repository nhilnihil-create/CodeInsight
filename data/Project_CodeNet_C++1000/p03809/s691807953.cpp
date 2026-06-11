/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#include<bits/stdc++.h>
#define ll long long
#define inf 1000000005
#define put putchar('\n')
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,t) for (int i=head[t];i;i=Next[i])
#define sqr(x) ((x)*(x))
#define re register
#define mp make_pair
#define fi first
#define se second
#define pa pair<int,int>
#define pb push_back
#define be begin()
#define en end()
#define mod 1000000007
#define N 500055
//#define int ll
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){char c=getchar();int tot=1;while ((c<'0'|| c>'9')&&c!='-') c=getchar();if (c=='-'){tot=-1;c=getchar();}
int sum=0;while (c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}return sum*tot;}
inline void wr(int x){if (x<0) {putchar('-');wr(-x);return;}if(x>=10)wr(x/10);putchar(x%10+'0');}
inline void wrn(int x){wr(x);put;}inline void wri(int x){wr(x);putchar(' ');}
inline void wrn(int x,int y){wri(x);wrn(y);}inline void wrn(int a,int b,int c){wri(a);wrn(b,c);}
int n,m,a[N],f[N],fa[N];
int nedge,Next[N*2],head[N],to[N*2],in1[N];
#define V to[i]
void add(int a,int b){
	Next[++nedge]=head[a];head[a]=nedge;to[nedge]=b;
}
void add_ne(int a,int b){add(a,b);add(b,a);in1[a]++;in1[b]++;}
void ret(){puts("NO");exit(0);}
void dfs(int x){
	f[x]=a[x];
	int sum=0,ma=-1;
	go(i,x){
		if (V==fa[x]) continue;
		fa[V]=x;dfs(V);sum+=f[V];ma=max(ma,f[V]);
	}
	if (ma==-1) return;
	if (sum<a[x]) ret();
	if (sum>a[x]*2) ret();
	f[x]=a[x]-(sum-a[x]);
	if (sum-a[x]>sum-ma) ret();
	if (fa[x]==-1&&a[x]*2!=sum) ret();
}
signed main(){
	n=read();F(i,1,n) a[i]=read();
	F(i,1,n-1) add_ne(read(),read());
	if (n==2){
		if (a[1]==a[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	F(i,1,n){
		if (in1[i]>=2){
			fa[i]=-1;dfs(i);break;
		}
	}
	puts("YES");
	return 0;
}