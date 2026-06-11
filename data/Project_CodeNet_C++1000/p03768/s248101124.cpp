#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5,MAX_M=1e5,MAX_Q=1e5,MAX_D=10;

int N,M,Q,v[MAX_Q],d[MAX_Q],c[MAX_Q];
vector<int> G[MAX_N];
bool flg[MAX_N][MAX_D+1];
int col[MAX_N];
void dfs(int v,int d,int c){
	flg[v][d]=true;
	if (d==0){
		if (!col[v]){
			col[v]=c;
		}
	}else{
		if (!flg[v][d-1]){
			dfs(v,d-1,c);
		}
		for(auto e:G[v]){
			if (!flg[e][d-1]){
				dfs(e,d-1,c);
			}
		}
	}
}

int main(){
	cin>>N>>M;
	REP(i,M){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cin>>Q;
	memset(flg,false,sizeof(flg));
	REP(i,Q){
		cin>>v[i]>>d[i]>>c[i];
		v[i]--;
	}
	REP(i,Q){
		if (!flg[v[Q-1-i]][d[Q-1-i]]){
			dfs(v[Q-1-i],d[Q-1-i],c[Q-1-i]);
		}
	}
	REP(i,N){
		cout<<col[i]<<endl;
	}
	return 0;
}