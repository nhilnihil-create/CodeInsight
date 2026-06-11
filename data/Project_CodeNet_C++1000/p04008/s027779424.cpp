#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
#define gc getchar
#define pc putchar
#define fi first
#define queue QQQ
#define se second
#define debug(x) cout << #x" = " << x << endl;
#define pp(x,y) cout << "pp: " << x << " " << y << endl;
#define rank __RANK
inline ll read(){
	register ll x=0,f=1;register char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
#define rd read
void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
const int maxn = 1e5+233;
int dis[maxn],dep[maxn];
vector<int> e[maxn];
int n,k,ans;
void dfs(int u,int fa){
	dis[u] = dep[u];
	for(auto v : e[u]){
		dep[v] = dep[u] + 1;
		dfs(v,u);
		dis[u] = max(dis[u],dis[v]);
	}
	if(fa != 1 && u != 1 && dis[u] - dep[u] == k-1){
		++ans;
		dis[u] = 0;
	}
}
int main(){
	n = rd(),k = rd();
	Rep(i,1,n){
		int x = rd();
		if(i==1) ans += (x != 1); else
		e[x] . push_back(i);
	}
	dfs(1,0);
	writeln(ans);
	return 0;
}