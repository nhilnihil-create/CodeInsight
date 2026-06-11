#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m,x,y;
	cin >> n >> m;
	vector<ll> adjlist[n+1];
	for(ll i=0; i<m; i++){
		cin >> x >> y;
		adjlist[x].emplace_back(y);
		adjlist[y].emplace_back(x);
	}
	for(ll i=1; i<=n; i++)
		cout << adjlist[i].size() << "\n";
	return 0;
}