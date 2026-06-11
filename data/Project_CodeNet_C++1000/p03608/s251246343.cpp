#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
using namespace std;

int main() {
	int N, M, R;
	cin>>N>>M>>R;
	int r[R];
	for(int i=0;i<R;++i){
		cin>>r[i];
		r[i]--;
	}
	long cost[N][N];
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(i==j)cost[i][j] = 0;
			else cost[i][j] = 1e9+7;
		}
	}

	long A, B, C;
	for(int i=0;i<M;++i){
		cin>>A>>B>>C;
		A--;
		B--;
		if(cost[A][B] > C){
			cost[A][B] = C;
			cost[B][A] = C;
		}
	}

	long DP[N][N];
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			DP[i][j] = cost[i][j];
		}
	}

	for(int k=0;k<N;++k){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
			}
		}
	}

	/**
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cout<<DP[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	**/

	stack<pair<int, long> > statestack;
	stack<map<int, int> > mapstack;
	for(int i=0;i<R;++i){
		statestack.push(make_pair(r[i], 0));
		map<int, int> map1;
		map1[r[i]]++;
		mapstack.push(map1);
	}
	long ans = 1e9+7;
	pair<int, long> state;
	map<int, int> statemap;
	while(!statestack.empty()){
		state = statestack.top();
		statemap = mapstack.top();
		statestack.pop();
		mapstack.pop();
		int owari = 1;
		for(int i=0;i<R;++i){
			if(statemap[r[i]]==0)owari = 0;
		}
		if(owari==1){
			if(state.second < ans)ans = state.second;
			continue;
		}
		for(int i=0;i<R;++i){
			if(state.first==r[i])continue;
			if(statemap[r[i]]==0){
				statemap[r[i]] = 1;
				statestack.push(make_pair(r[i], state.second + DP[state.first][r[i]]));
				mapstack.push(statemap);
				statemap[r[i]] = 0;
			}
		}
	}
	cout<<ans<<endl;
}
