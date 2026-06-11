#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x=0;char ch=gc();bool positive=1;
	for(;!isdigit(ch);ch=gc()) if(ch=='-') positive=0;
	for(;isdigit(ch);ch=gc()) x=x*10+ch-'0';
	return positive?x:-x;
}
inline void write(ll x){
	if(x<0){
		x=-x;putchar('-');
	}
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline void writeln(ll x){write(x);puts("");}
inline void writep(ll x){write(x);putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=1e5+5;
int head[N],opt;
ll a[N];
poly v[N];
bool d=1;
void dfs(int u,int fa){
	ll sum=0,mx=0;int t=0;
	for(auto k:v[u]){
		if(k==fa) continue;
		dfs(k,u);t++;
		sum+=a[k];mx=max(mx,a[k]);
	}
	if(t==0) return;
	ll x=sum-a[u],y=2*a[u]-sum;
	if(x<0||y<0||x>min(sum-mx,sum/2)||(fa==0&&y)) d=0;
	a[u]=y;
}
int main(){
	int n=read();
	For(i,1,n) a[i]=read();
	For(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y);v[y].pb(x);
	}
	int rt=0;
	For(i,1,n) if(v[i].size()>1) rt=i;
	if(rt) dfs(rt,0);
	else d=(a[1]==a[2]);
	if(d) puts("YES");
	else puts("NO");
}