/*
{By GWj

*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=100000+20;
int dp[MAXN][2];
vector<int> g[MAXN];
int n,m;
int save=0;
int main(){
	fastio;
	R2(n,m);
	rb(i,1,m){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	set<pair<int,pair<int,bool> >> heap;
	memset(dp,63,sizeof(dp));
	rb(i,1,n)
		dp[i][0]=i,heap.insert(II(i,II(i,0)));
	while(!heap.empty()){
		pair<int,pair<int,bool> > now=*heap.begin();
		heap.erase(heap.begin());
		int i,j,val;
		i=now.SEC.FIR;
		j=now.SEC.SEC;
		val=now.FIR;
		if(dp[i][j]!=val) continue;
		for(auto it:g[i]){
			if(dp[it][j^1]>dp[i][j]){
				dp[it][j^1]=dp[i][j];
				heap.insert(II(val,II(it,j^1)));
			}
		}
	}
	int N=0;
	rb(i,1,n){
		N+=g[i].empty();
	}
	int save1=0,save0=0,save3=0;
	rb(i,1,n){
		if(g[i].size()){
			if(dp[i][0]==i){
				save3+=dp[i][1]>=i;
				save0++;
			}
			if(dp[i][1]>=i){
				save1++;
			}
		}
		
	}
	LL rest=1ll*N*n*2-1ll*N*N;
	rb(i,1,n){
		if(g[i].size())
		if(min(dp[i][0],dp[i][1])==i){
			if(dp[i][0]==i&&dp[i][1]==i){
				rest+=save3;
			}
			else{
				rest+=save0;
			}
		}
	}
	cout<<rest<<endl;
	return 0;
}