#include<bits/stdc++.h>
using namespace std;

const int _ = 4003; vector < int > nxt[_]; int N , K;
int dfs(int x , int p , int l){
	int cnt = x <= N;
	if(l < K) for(auto t : nxt[x]) if(t != p) cnt += dfs(t , x , l + 1);
	return cnt;
}

int main(){
	cin >> N >> K;
	for(int p , q , i = 1 ; i < N ; ++i){
		cin >> p >> q; nxt[p].push_back(N + i); nxt[q].push_back(N + i);
		nxt[N + i].push_back(p); nxt[N + i].push_back(q);
	}

	int mx = 0;
	if(K & 1) for(int i = N + 1 ; i < 2 * N ; ++i) mx = max(mx , dfs(i , 0 , 0));
	else for(int i = 1 ; i <= N ; ++i) mx = max(mx , dfs(i , 0 , 0));
	cout << N - mx;
	return 0;
}
