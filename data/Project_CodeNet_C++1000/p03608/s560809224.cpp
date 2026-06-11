#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = 1e8;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m, r;
	cin>>n>>m>>r;
	vector<int> v(r), p(r);
	for(int i = 0; i < r; i++){
		cin>>v[i];
		p[i] = i;
	}
	vector<vector<int> > dist(n + 1, vector<int>(n + 1, inf));
	for(int i = 1; i <= n; i++){
		dist[i][i] = 0;
	}
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin>>a>>b>>c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	ll ans = inf;
	while(true){
		ll sum = 0;
		for(int i = 1; i < r; i++){
			sum += dist[v[p[i - 1]]][v[p[i]]];
		}
		ans = min(ans, sum);
		if(!next_permutation(p.begin(), p.end()))break;
	}
	cout<<ans<<'\n';

	return 0;
}