#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll ,ll>;
const ll INF = 1LL<<61LL;

ll N;
vector<vector<ll> > es;

ll dfs(ll now){
	vector<ll> ret;
	for(auto &&e : es[now]){
		ret.push_back(dfs(e));
	}
	sort(ret.begin(), ret.end());
	ll ans = 0;
	for(int i=0;i<ret.size();i++){
		ans = max(ans, ret[i] + (int)ret.size() - i);
	}
	return ans;
}

int main(){
	cin >> N;
	es.resize(N);
	for(int i=1;i<N;i++){
		ll a;
		cin >> a;
		a--;
		es[a].push_back(i);
	}
	ll ans = 0;
	ans = dfs(0);
	cout << ans << endl;
}
