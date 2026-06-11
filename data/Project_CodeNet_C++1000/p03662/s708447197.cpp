#include<bits/stdc++.h>
using namespace std;
int aaaaaaaaaaaaa;
#define ALL(x) (x).begin(),(x).end()
#define uniq(x) (x).erase(unique(ALL(x)),(x).end())
#define SORT(x) sort(ALL(x))
#define REV(x) reverse(ALL(x))
#define foreach(it,x) for(__typeof((x).begin()) it=(x).begin();it!=(x).end();it++)
#define debug(x) cerr<<#x<<"="<<(x)<<endl
#define gett() cerr<<"Time:"<<clock()<<"ms."<<endl
#define ri(x) scanf("%d",&x)
#define rl(x) scanf("%lld",&x)
#define rlcfpoj(x) scanf("%I64d",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define plcfpoj(x) printf("%I64d",x)
#define lfd() printf("\n")
#define sp() printf(" ")
#define inrep(x) int x;scanf("%d",&x);while(x--)
#define testbit(mask,i) (((mask)>>(i))&1)
#define setbit(mask,i) ((mask)|(1<<i))
#define delbit(mask,i) ((mask)^(1<<i))
int n,u,v;
int dist1[100100],dist2[100100];
vector<int> ga[100100];
void dfs1(int u,int p){
	dist1[u]=dist1[p]+1;
	for(int i=0;i<ga[u].size();i++){
		int v=ga[u][i];
		if(v!=p)
			dfs1(v,u);
	}
}
void dfs2(int u,int p){
	dist2[u]=dist2[p]+1;
	for(int i=0;i<ga[u].size();i++){
		int v=ga[u][i];
		if(v!=p)
			dfs2(v,u);
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		ga[u].push_back(v);
		ga[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(n,0);
	int snuke=0,fennec=0;
	for(int i=1;i<=n;i++){
		if(dist1[i]<=dist2[i])
			fennec++;
		else
			snuke++;
	}
	if(snuke>=fennec)
		cout<<"Snuke"<<endl;
	else
		cout<<"Fennec"<<endl;
	return 0;
}
