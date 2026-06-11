#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f,oo = inf;
#define pi 3.14159265358979323846
#define IL inline
#define RG register
#define rep(i,a,b) for(RG int i=(a);i<(b);++i)
#define Rep(i,a,b) for(RG int i=(a);i<=(b);++i)
#define Dep(i,a,b) for(RG int i=(a);i>=(b);--i)
#define pc putchar
/*char __wzp[1<<15|1],*__S=__wzp+32768;
#define gc() (__S>=__wzp+32768?(__wzp[fread(__wzp,sizeof(char),1<<15,stdin)]=EOF),*((__S=__wzp)++):*(__S++))*/
#define gc getchar
IL ll read(){
    RG ll x=0;char f=0;RG char c=gc();
    for(;!isdigit(c);c=gc())f|=(c=='-');
    for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
    return f?-x:x;
}
IL double readdb(){
    RG double x=0,p=0.1;RG char f=0,c=gc();
    for(;!isdigit(c);c=gc())f|=(c=='-');
    for(;isdigit(c);c=gc())x=x*10+(c^48);
    if(c=='.')for(c=gc();isdigit(c);c=gc(),p/=10)x=x+(c^48)*p;
    return f?-x:x;
}
IL void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);pc(x%10+'0');}
IL void writeln(ll x){write(x);puts("");}
IL void writeln(ll x,char c,ll y){write(x);pc(c);writeln(y);}
IL void writeln(ll x,char c,ll y,char d,ll z){write(x);pc(c);write(y);pc(d);writeln(z);}
#define debug(x) printf(#x" = %d\n",x);
#define rd() read()
#define rdb() readdb()
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))
#define fin(x) freopen(#x".in","r",stdin)
#define fout(x) freopen(#x".out","w",stdout)
#define y1 ____y1
#define hash __hash
#define union _union
const int maxn = 100500;
int sg[maxn],n,m;
vector<int> edge[maxn];
void dfs(int u,int fa){
	sg[u] = 0;
	for(unsigned i=0;i<edge[u].size();++i){
		int v = edge[u][i];
		if(v ==fa) continue;
		dfs(v,u);
		sg[u] ^= (sg[v] + 1);
	}
}
int main(){
	n = rd();
	Rep(i,1,n) edge[i].clear();
	rep(i,1,n){
		int a = rd(),b = rd();
		edge[a] . push_back(b);
		edge[b] . push_back(a);
	}
	dfs(1,0);
	puts(sg[1] ? "Alice" : "Bob");
	return 0;
}