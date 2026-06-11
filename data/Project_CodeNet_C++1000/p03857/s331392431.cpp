#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#define SF scanf
#define PF printf
#define MAXN 200010
using namespace std;
int a[MAXN];
int n,m,k;
int fa[MAXN][2];
pair<int,int> l1[MAXN],l2[MAXN];
map<pair<int,int> ,int> mp;
int get_fa(int x,int id){
	if(fa[x][id]==0)
		return x;
	fa[x][id]=get_fa(fa[x][id],id);
	return fa[x][id];
}
int merge(int x,int y,int id){
	int fx=get_fa(x,id);
	int fy=get_fa(y,id);
	if(fx!=fy)
		fa[fx][id]=fy;
}
int main(){
	SF("%d%d%d",&n,&m,&k);
	int u,v;
	for(int i=1;i<=m;i++){
		SF("%d%d",&u,&v);
		merge(u,v,0);
	}
	for(int i=1;i<=k;i++){
		SF("%d%d",&u,&v);
		merge(u,v,1);
	}
	for(int i=1;i<=n;i++)
		mp[make_pair(get_fa(i,0),get_fa(i,1))]++;
	for(int i=1;i<=n;i++)
		PF("%d ",mp[make_pair(get_fa(i,0),get_fa(i,1))]);
	
}