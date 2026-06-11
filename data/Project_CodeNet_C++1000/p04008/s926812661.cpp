#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N,K;
vector<int>G[100001];
int a[100001];
int ans=0;
int dfs(int x,int d){
	/*if(G[x].size()==0){
		/*if(d>K){
			return 1;
		}else{
			return 0;
		}
		return 1;
	}*/
	int ma=0;
	REP(i,G[x].size()){
		int a=dfs(G[x][i],d+1);
		ma=max(a,ma);
	}
	if(ma==K-1&&d!=1&&d!=0){
		ans++;
		//cout<<x<<endl;
		return 0;
	}
	/*
	if(d>K){
		return ma+1;
	}else{
		return ma;
	}
	*/
	return ma+1;
}

int main(){
	cin>>N>>K;
	REP(i,N){
		cin>>a[i];
		a[i]--;
	}
	if(a[0]!=0){
		ans++;
		a[0]=0;
	}
	
	if(K==1){
		REP(i,N){
			if(a[i]!=0)ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	
	for(int i=1;i<N;i++){
		G[a[i]].push_back(i);
	}
	int a=dfs(0,0);
	//if(a!=0)ans++;
	cout<<ans<<endl;
	return 0;
}