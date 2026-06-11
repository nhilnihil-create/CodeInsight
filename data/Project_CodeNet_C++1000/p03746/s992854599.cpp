#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N,M;
vector<int>v[100010];
vector<int>w[2];
bool used[100010];
void dfs(int x,int num){
	w[num].push_back(x);
	used[x]=true;
	REP(i,v[x].size()){
		if(used[v[x][i]]==false){
			dfs(v[x][i],num);
			break;
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
		v[a].push_back(b);
		v[b].push_back(a);
	}
	REP(i,N){
		used[i]=false;
	}
	dfs(0,0);
	dfs(0,1);
	reverse(w[0].begin(),w[0].end());
	cout<<w[0].size()+w[1].size()-1<<endl;
	REP(i,w[0].size()-1){
		cout<<w[0][i]+1<<" ";
	}
	REP(i,w[1].size()){
		cout<<w[1][i]+1;
		if(i==w[1].size()-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
	return 0;
}