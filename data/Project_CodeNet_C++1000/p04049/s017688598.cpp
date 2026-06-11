#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> G;
int A[2020], B[2020], dep[2020];

void dfs(int key){
	for(int i=0; i<G[key].size(); ++i){
		int nx=A[G[key][i]]+B[G[key][i]]-key;
		if(dep[nx]==4000){
			dep[nx]=dep[key]+1;
			dfs(nx);
		}
	}
}

int main() {
	int N, K;
	cin >> N >> K;
	G.resize(N+1);
	for(int i=1; i<N; ++i){
		cin >> A[i] >> B[i];
		G[A[i]].emplace_back(i);
		G[B[i]].emplace_back(i);
	}
	int ans=0;
	if(K%2==0){
		for(int i=1; i<=N; ++i){
			for(int j=1; j<=N; ++j) dep[j]=4000;
			dep[i]=0;
			dfs(i);
			int cnt=0;
			for(int j=1; j<=N; ++j){
				if(dep[j]*2<=K) ++cnt;
			}
			ans=max(ans, cnt);
		}
	}else{
		for(int i=1; i<N; ++i){
			for(int j=1; j<=N; ++j) dep[j]=4000;
			dep[A[i]]=dep[B[i]]=0;
			dfs(A[i]);
			dfs(B[i]);
			int cnt=0;
			for(int j=1; j<=N; ++j){
				if(dep[j]*2<K) ++cnt;
			}
			ans=max(ans, cnt);
		}
	}
	cout << N-ans << endl;
	return 0;
}