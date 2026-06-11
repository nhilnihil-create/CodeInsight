/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
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
int up[100000+20];
int n;
int a[100000+20];
vector<int> g[100000+20];
bool check(vector<int> v,LL x,LL sum){
	for(auto& it:v){
		if(it*2>sum){
			sum-=(2*it+1-sum)/2;
			return (sum/2)>=x;
		}
	}
	return (sum/2)>=x;
}
void dfs(int now,int prev=0){
	if((!prev)+g[now].size()==1){
		up[now]=a[now];
		return ;
	}
	LL sum=0;
	vector<int> v;
	for(auto it:g[now]){
		if(it!=prev){
			dfs(it,now);
			sum+=up[it];
			v.PB(up[it]);
		}
	}
	if(sum<a[now]){
		cout<<"NO"<<endl;
		exit(0);
	}
	if(!check(v,sum-a[now],sum)){
		cout<<"NO"<<endl;
		exit(0);
	}
	up[now]=a[now]+a[now]-sum;
	if(up[now]<0){
		cout<<"NO"<<endl;
		exit(0);
	}
}
int main(){
	fastio;
	int n;
	R(n);
	rb(i,1,n)
		R(a[i]);
	rb(i,1,n-1){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	int root=-1;
	rb(i,1,n)
		if(g[i].size()!=1) root=i;
	if(root==-1){
		cout<<(a[1]==a[2]? "YES":"NO");
		return 0;
	}
	dfs(root);
	if(up[root]==0)
	cout<<"YES"<<endl;
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
/** 程序框架：
  *
  *
  *
  *
  **/
