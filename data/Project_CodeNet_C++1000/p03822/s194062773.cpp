#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define gc getchar
#define ll long long
#define db double
#define pii pair<int,int>
#define fi first
#define se second
#define Vi vector<int>
#define Vp vector<pii>

using namespace std;

inline void cmax(int &x,int y){y>x?x=y:0;}
inline void cmin(int &x,int y){y<x?x=y:0;}

int read(){
	char ch=gc(); int x=0,op=1;
	for (;!isdigit(ch);ch=gc()) if (ch=='-') op=-1;
	for (;isdigit(ch);ch=gc()) x=(x<<1)+(x<<3)+ch-'0';
	return x*op;
}

const int N=2e5+10;
int n,m,x,f[N],tp,q[N]; Vi G[N];

void dfs(int u){
	for (auto v:G[u]) dfs(v);
	tp=0;
	for (auto v:G[u]) q[++tp]=f[v];
	sort(q+1,q+1+tp,greater<int>());
	rep (i,1,tp) f[u]=max(f[u],q[i]+i);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	rep (i,2,n) cin>>x,G[x].push_back(i);
	dfs(1);
	printf("%d\n",f[1]);
	return 0;
}
