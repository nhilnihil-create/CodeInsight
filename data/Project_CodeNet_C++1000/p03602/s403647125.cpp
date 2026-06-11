#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1145148931919810;
int main(){
	ll n; cin >> n;
	ll edge[n][n];
	ll d[n][n];
	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < n; ++j){
			cin >> edge[i][j];
			d[i][j] = edge[i][j];
		}
	}
	for(ll k = 0; k < n; ++k)for(ll i = 0; i < n; ++i)for(ll j = 0; j < n; ++j) d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
	ll ans = 0;
	for(ll i = 0; i < n; ++i){
		for(ll j = i + 1; j < n; ++j){
			if(edge[i][j] > d[i][j]){
				cout << "-1\n";
				return 0;
			}
			bool po = 1;
			for(ll k = 0; k < n; ++k){
				if(k == i || k == j) continue;
				if(d[i][k] + d[k][j] == edge[i][j]) po = 0;
			}
			ans += edge[i][j] * po;
		}
	}
	cout << ans << endl;
	return 0;
}