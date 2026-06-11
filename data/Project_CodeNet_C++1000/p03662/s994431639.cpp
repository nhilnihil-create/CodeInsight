#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5;
int N;
vector<int> G[MAX_N];
int cnt[2],dis[2][MAX_N];

void bfs(int f){
	int s=(f==0 ? 0 : N-1);
	memset(dis[f],-1,sizeof(dis[f]));
	dis[f][s]=0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(auto e:G[v]){
			if (dis[f][e]==-1){
				dis[f][e]=dis[f][v]+1;
				que.push(e);
			}
		}
	}
}
int main(){
	cin>>N;
	REP(i,N-1){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bfs(0);
	bfs(1);
	REP(i,N){
		if (dis[0][i]<=dis[1][i]){
			cnt[0]++;
		}else{
			cnt[1]++;
		}
	}
	cout<<(cnt[0]>cnt[1] ? "Fennec" : "Snuke")<<endl;
	return 0;
}