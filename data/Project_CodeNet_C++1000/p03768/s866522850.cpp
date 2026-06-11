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
int v[100010],d[100010],col[100010];
int mx[100010],qq[100010],ans[100010];
int n,m,p;
vector<int>G[100010];
void go(int inp){
	int x=v[inp],dd=d[inp],cc=col[inp];
	if(dd<=mx[x])return;
	mx[x]=dd;
	qq[0]=x;
	int rr=1;
	for(int i=0;i<rr;i++){
		int x=qq[i];
		if(!ans[x])ans[x]=cc;
		if(!mx[x])continue;
		for(auto to:G[x]){
			int nxt=mx[x]-1;
			if(nxt>mx[to]){
				mx[to]=nxt;
				qq[rr++]=to;
			}
		}
	}
}
int main(){
	memset(mx,-1,sizeof(mx));
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	cin>>p;
	for(int i=0;i<p;i++)cin>>v[i]>>d[i]>>col[i],v[i]--;
	for(int i=p-1;i>=0;i--)go(i);
	for(int i=0;i<n;i++)cout<<ans[i]<<endl;
	return 0;
}
