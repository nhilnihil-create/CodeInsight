#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
pair<int,int> dp[MAXN][12];
int n,m,q;
vector<int> a[MAXN];
int main(){
	SF("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++){
		SF("%d%d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	SF("%d",&q);
	int d,c;
	for(int i=1;i<=q;i++){
		SF("%d%d%d",&v,&d,&c);
		dp[v][d]=make_pair(i,c);
	}
	for(int k=9;k>=0;k--)
		for(int i=1;i<=n;i++){
			dp[i][k]=max(dp[i][k],dp[i][k+1]);
			for(int j=0;j<int(a[i].size());j++){
				v=a[i][j];
				dp[i][k]=max(dp[i][k],dp[v][k+1]);
			}
		}
	for(int i=1;i<=n;i++)
		PF("%d\n",dp[i][0].second);
}