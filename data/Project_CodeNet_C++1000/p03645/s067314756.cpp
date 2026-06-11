#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	int n, m; cin >> n >> m;
	G g; g.resize(n+1);
	for(int i=0;i<m;i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	map<int, int> mp;
	for(auto c: g[1]){
		mp[c]++;
	}
	for(auto c: g[n]){
		mp[c]++;
	}
	for(auto kv: mp){
		if(kv.second==2){
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}