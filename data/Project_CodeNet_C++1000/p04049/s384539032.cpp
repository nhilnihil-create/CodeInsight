#include<bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define uniq(x) (x).erase(unique(ALL(x)),(x).end())
#define SORT(x) sort(ALL(x))
#define REV(x) reverse(ALL(x))
#define foreach(it,x) for(__typeof((x).begin()) it=(x).begin();it!=(x).end();it++)
#define debug(x) cerr<<#x<<"="<<(x)<<endl
#define gett() cerr<<"Time:"<<clock()<<"ms."<<endl
#define ri(x) scanf("%d",&x);
#define rl(x) scanf("%lld",&x);
#define rlcfpoj(x) scanf("%I64d",&x);
#define pi(x) printf("%d",x);
#define pl(x) printf("%lld",x);
#define plcfpoj(x) printf("%I64d",x);
#define lfd() printf("\n");
#define sp() printf(" ");
vector<int> ga[2001];
int n,k;
bool vis[2001];
int u,v;
int dfs(int u,int max_dist){
	if(max_dist==0)
		return 1;
	vis[u]=true;
	int res=1;
	for(int i=0;i<ga[u].size();i++)
	{
		if(!vis[ga[u][i]])
			res+=dfs(ga[u][i],max_dist-1);
	}
	return res;
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		ga[u].push_back(v);
		ga[v].push_back(u);
	}
	int maxx=0;
	if(k%2==0){
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			int tmp=dfs(i,k/2);
			maxx=max(maxx,tmp);
		}
	}
	if(k%2==1){
		for(int i=1;i<=n;i++){
			for(int j=0;j<ga[i].size();j++){
				int l=ga[i][j];
				memset(vis,0,sizeof(vis));
				vis[i]=vis[l]=true;
				maxx=max(maxx,dfs(i,k/2)+dfs(l,k/2));
			}
		}
	}
	cout<<n-maxx<<endl;
	return 0;
}
