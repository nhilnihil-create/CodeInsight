#include<algorithm>
#include<clocale>
#include<cmath>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<istream>
#include<map>
#include<math.h>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
vector<int> adj[100005];
int color[100005],f[100005],v[100010],d[100010],c[100010],n,m,q,a,b,mxd[100010];
void dfs(int node,int D,int C){
	if (mxd[node]>=D) return ;
	if (color[node]==0) color[node]=C;
	if (d==0) return ;
	mxd[node]=D;
	for (int i=0;i<adj[node].size();i++) dfs(adj[node][i],D-1,C);
}
int main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin>>q;
	for (int i=0;i<q;i++) cin>>v[i]>>d[i]>>c[i];
	memset(mxd,-1,sizeof(mxd));
	for (int i=q-1;i>=0;i--) dfs(v[i],d[i],c[i]);
	for (int i=1;i<=n;i++) cout<<color[i]<<endl;
	return 0;
}