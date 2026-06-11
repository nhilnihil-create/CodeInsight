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

	int n, m;
	cin>>n>>m;
	vector<int> a(m), b(m), c(m);
	vector<vector<int> > dist(n + 1, vector<int>(n + 1, inf));
	for(int i = 1; i <= n; i++){
		dist[i][i] = 0;
	}
	for(int i = 0; i < m; i++){
		cin>>a[i]>>b[i]>>c[i];
		dist[a[i]][b[i]] = c[i];
		dist[b[i]][a[i]] = c[i];
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		bool flg = false;
		for(int u = 1; u <= n; u++){
			for(int v = 1; v <= n; v++){
				if(dist[u][a[i]] + c[i] +  dist[b[i]][v] == dist[u][v]){
					flg = true;
					break;
				}
			}
			if(flg)break;
		}
		if(!flg)ans++;
	}
	cout<<ans<<endl;


	return 0;
}