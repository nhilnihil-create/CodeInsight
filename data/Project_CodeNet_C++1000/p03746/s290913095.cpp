#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100010
int n,num,m,h[N],vis[N];
struct node{int to,next;}mp[N<<1];
vector<int>ans;
inline void ins(int x,int y){
	mp[++num].to=y;mp[num].next=h[x];h[x]=num;
	mp[++num].to=x;mp[num].next=h[y];h[y]=num;
}
void dfs(int x,int rt){
	for(int i=h[x];i;i=mp[i].next){
		int y=mp[i].to;if(y==rt || vis[y]) continue;
		vis[y]=1;ans.push_back(y);dfs(y,rt);return;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;scanf("%d%d",&x,&y);
		ins(x,y);
	}
	dfs(1,1);
	reverse(ans.begin(),ans.end());
	dfs(mp[h[1]].to,mp[h[1]].to);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();++i) printf("%d ",ans[i]);
	return 0;
}