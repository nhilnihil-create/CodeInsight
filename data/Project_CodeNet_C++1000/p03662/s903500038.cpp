/*

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<stack>
using namespace std;
#define ll long long
#define N 100003
#define INF 0x3f3f3f3f
#define lson rt<<1, l, mid
#define rson (rt<<1)|1, mid+1, r
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define mkp make_pair
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
int n, d[N][2], vis[N];
vector<int>g[N];
void dfs(int cur, int dep, int type){
	int i, now;
	d[cur][type] = dep;
	for(i=0; i<g[cur].size(); i++){
		now = g[cur][i];
		if(vis[now])
			continue;
		vis[now] = 1;
		dfs(now, dep+1, type);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("fs.in", "r", stdin);
	//freopen("E1.out", "w", stdout);
	int i, j, t, x, y;
	cin>>n;
	for(i=1; i<n; i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	vis[1] = 1;
	dfs(1, 0, 0);
	memset(vis, 0, sizeof(vis));
	vis[n] = 1;
	dfs(n, 0, 1);
	int b=0;
	for(i=1; i<=n; i++)
		if(d[i][0]<=d[i][1])
			b++;
	//for(i=1; i<=n; i++)cout<<d[i][0]<<' ';cout<<endl;
	//for(i=1; i<=n; i++)cout<<d[i][1]<<' ';cout<<endl;
	if(b>n-b)
		cout<<"Fennec"<<endl;
	else
		cout<<"Snuke"<<endl;
	return 0;
}
