#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
vector<int>g[110000];
int vis[110000];
int dist[110000];
bool bin=true;
int ad=0;
void dfs(int a){
	ad++;
	vis[a]=1;
	for(int i=0;i<g[a].size();i++){
		if(vis[g[a][i]]==1){
			if(dist[g[a][i]]%2==dist[a]%2){
				bin=false;
			}
			continue;
		}
		dist[g[a][i]]=dist[a]+1;
		dfs(g[a][i]);
	}
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	int sg=0;
	int bi=0;
	int ot=0;
	for(int i=0;i<a;i++){
		if(vis[i])continue;
		bin=true;ad=0;
		dfs(i);
		if(ad==1)sg++;
		else if(bin)bi++;
		else ot++;
	}
	long long ret=0;
	ret+=(long long)sg*a*2-(long long)sg*sg;
	ret+=(long long)(bi+ot)*(bi+ot)+(long long)bi*bi;
	printf("%lld\n",ret);
}