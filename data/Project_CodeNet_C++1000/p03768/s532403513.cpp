#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};
const long long llinf=9223372036854775807ll;
const int N=100005;
int n,m,q,tot,fst[N],pnt[N*2],nxt[N*2],ans[N],dp[N][11],a,b;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		pnt[++tot]=b;
		nxt[tot]=fst[a];
		fst[a]=tot;
		pnt[++tot]=a;
		nxt[tot]=fst[b];
		fst[b]=tot;
	}
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>a>>b>>ans[i],dp[a][b]=i;
	for(int i=9;i>=0;i--)
		for(int x=1;x<=n;x++)
		{
			dp[x][i]=max(dp[x][i],dp[x][i+1]);
			for(int j=fst[x];j;j=nxt[j])
				dp[x][i]=max(dp[x][i],dp[pnt[j]][i+1]);
		}
	for(int i=1;i<=n;i++)
		cout<<ans[dp[i][0]]<<'\n';
	return 0;
}