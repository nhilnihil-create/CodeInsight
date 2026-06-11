#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool solve(const vector<vector<int>>& g, const vector<int>& A){
	const int N = g.size();
	vector<int> deg(N);
	vector<long long> rest(N);
	queue<int> qu;
	for(int i=0;i<N;i++){
		deg[i] = g[i].size();
		rest[i] = A[i];
		if(g[i].size() == 1){
			qu.push(i);
		} else {
			rest[i] *= 2;
		}
	}
	vector<int> visit(N, 0);
	while(!qu.empty()){
		int p = qu.front(); qu.pop();
		if(rest[p] > A[p]) return false;
		visit[p] = 1;
		for(auto& t : g[p]){
			if(visit[t]) continue;
			if(A[t] < rest[p]) return false;
			rest[t] -= rest[p];
			rest[p] = 0;
			if(rest[t] < 0) return false;
			--deg[t];
			if(deg[t] == 1) qu.push(t);
		}
		if(rest[p] != 0) return false;
	}
	return true;
}

int main(){
	int N;
	while(cin >> N){
		vector<int> A(N);
		for(auto& t : A) cin >> t;
		vector<vector<int>> g(N);
		for(int i=0;i<N-1;i++){
			int a, b; cin >> a >> b;
			--a; --b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		cout << (solve(g, A) ? "YES" : "NO") << endl;
	}
}
