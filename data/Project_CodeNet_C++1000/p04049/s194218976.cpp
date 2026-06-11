#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000

int bfs(vector<vector<int>> &E,int start,int next,int K){
	vector<int> dis(E.size(),Inf);
	dis[start] = 0;
	dis[next] = 0;
	queue<int> que;
	que.push(start);
	que.push(next);
	while(que.size()!=0){
		int now = que.front();
		que.pop();
		for(int i=0;i<E[now].size();i++){
			int to = E[now][i];
			if(dis[to]!=Inf)continue;
			dis[to] = dis[now] + 1;
			que.push(to);
		}
	}
	
	int cnt = 0;
	for(int i=0;i<E.size();i++){
		if(dis[i]<=K/2)cnt++;
	}
	
	return cnt;
}

		


int main(){
	
	int N,K;
	cin>>N>>K;
	
	vector<vector<int>> E(N,vector<int>(0));

	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	int maxi = 0;
	if(K%2==1){
		for(int i=0;i<N;i++){
			for(int j=0;j<E[i].size();j++){
				maxi = max(maxi,bfs(E,i,E[i][j],K));
			}
		}
	}
	else{
		for(int i=0;i<N;i++){
			maxi = max(maxi,bfs(E,i,i,K));
		}
	}
	cout<<N-maxi<<endl;
	
	
	return 0;
}
