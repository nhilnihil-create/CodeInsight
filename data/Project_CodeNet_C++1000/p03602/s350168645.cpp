#include <bits/stdc++.h>

using namespace std;

#define debug(x) '[' << #x << " is: " << x << "] "
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll dist[333][333];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	#ifndef ONLINE_JUDGE
	//	freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<vector<ll>> e(n,vector<ll> (n));
	vector<pair<ll,pair<ll,ll>>> edge;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>e[i][j];
			dist[i][j] = 1e18;
			if(i > j){
				edge.push_back({e[i][j],{i,j}});
			}
		}
	ll ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			bool good = 1;
			for(int x=0;x<n;x++){
				if(i == j || i == x || j == x)continue;
				if(e[x][j] + e[x][i] < e[i][j]){
					cout << "-1\n";
					return 0;
				}
				// cout << i << ' ' << j << ' ' << x << endl;
				// cout << e[x][j] + e[x][i] << ' ' << e[i][j] << endl;
				if(e[x][j] + e[x][i] == e[i][j])good=0;
			}
			ans += e[i][j] * good;
		}
	}
	cout << ans << endl;
}