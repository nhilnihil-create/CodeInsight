#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define rep(i,x) for(int (i)=1;(i)<=(x);(i)++)
#define repp(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
#define forn(i,x) for(int (i)=0;(i)<(x);(i)++)
#define foreach(i,x) for(auto (i):(x))
using namespace std;
typedef pair<int,int>pii;
int n,m,q;
int c[100010][20];
int co[100010];
vector<int>G[100010];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	cin>>q;
	for(int i=0;i<q;i++){
		int v,d;
		cin>>v>>d>>co[i+1];
		v--;
		c[v][d]=i+1;
	}
	for(int i=11-2;i>=0;i--)
		for(int v=0;v<n;v++)
			for(int u:G[v]){
				c[u][i]=max(c[u][i],c[v][i+1]);
			}
	for(int i=0;i<n;i++){
		int mx=0;
		for(int j=0;j<11;j++)mx=max(mx,c[i][j]);
		cout<<co[mx]<<endl;
	}
	return 0;
}
