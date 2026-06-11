#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N,K,L;
int color[200001];
int color2[200001];
vector<int>G[200001];
vector<int>G2[200001];
bool used[200001];

void dfs(int x,int c){
	color[x]=c;
	used[x]=true;
	REP(i,G[x].size()){
		if(used[G[x][i]]==false){
			dfs(G[x][i],c);
		}
	}
}


void ddfs(int x,int c){
	color2[x]=c;
	used[x]=true;
	REP(i,G2[x].size()){
		if(used[G2[x][i]]==false){
			ddfs(G2[x][i],c);
		}
	}
}

typedef pair<int,int>P;
int main(){
	cin>>N>>K>>L;
	REP(i,K){
		int p,q;
		cin>>p>>q;
		p--;q--;
		G[p].push_back(q);
		G[q].push_back(p);
	}
	REP(i,L){
		int r,s;
		cin>>r>>s;
		r--;s--;
		G2[r].push_back(s);
		G2[s].push_back(r);
	}
	REP(i,200001){
		color[i]=-1;
		color2[i]=-1;
		used[i]=false;
	}
	int c=0;
	REP(i,N){
		if(used[i]==false){
			dfs(i,c);
			c++;
		}
	}
	REP(i,200001){
		used[i]=false;
	}
	c=0;
	REP(i,N){
		if(used[i]==false){
			ddfs(i,c);
			c++;
		}
	}
	map<P,int>m;
	REP(i,N){
		m[P(color[i],color2[i])]++;
	}
	REP(i,N){
		//cout<<"a"<<color[i]<<" "<<color2[i]<<endl;
		cout<<m[P(color[i],color2[i])]<<endl;
	}
	return(0);
}