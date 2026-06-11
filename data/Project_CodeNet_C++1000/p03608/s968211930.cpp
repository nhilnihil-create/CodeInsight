#include <bits/stdc++.h>

using namespace std;

static const int MAX = 205;
static const long long inf = (1LL<<50);

int n;
long long d[MAX][MAX];

void floyd() {
	for(int k = 0; k < n; k++ ){
		for(int i = 0; i < n; i++){
			if(d[i][k] == inf) continue;
			for(int j = 0; j < n; j++){
				if(d[k][j] ==inf)continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {
	int e, u, v, c, r;
	cin >> n >> e >> r;
	vector<int> R(r);
	for(int i = 0; i < r; i++){
		cin>>R[i];
		R[i]--;
	}
	sort(R.begin(),R.end());
	for(int i = 0; i <n ;i++){
		for(int j = 0; j < n; j++){
			d[i][j] = ( (i == j)? 0 :inf);
		}
	}
	for(int i = 0; i < e; i++){
		cin >> u >> v >> c;
		--u,--v;
		d[u][v] = c;
		d[v][u] = c;
	}
	floyd();

	long long ans = inf;
	do{
		long long now = 0;
		for(int i = 0; i < r-1; i++){
			now += d[R[i]][R[i+1]];
		}
		ans = min(ans,now);
	} while(next_permutation(R.begin(),R.end()));
	cout << ans << endl;
}
