#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	int n; cin >> n;
	int a[105];
	map<string, int> m;
	rep(i, 0, n){
		cin >> a[i];
		if(a[i]<400) m["gray"]++;
		else if(a[i]<800) m["brown"]++;
		else if(a[i]<1200) m["green"]++;
		else if(a[i]<1600) m["cyan"]++;
		else if(a[i]<2000) m["brue"]++;
		else if(a[i]<2400) m["yellow"]++;
		else if(a[i]<2800) m["orange"]++;
		else if(a[i]<3200) m["red"]++;
		else if(a[i]>=3200) m["free"]++;
	}
	int ansmin = 0;
	int ansmax = 0;
	for(auto kv: m){
		ansmax++;
		if(kv.first!="free") ansmin++;
		if(kv.first=="free") ansmax += kv.second-1;
	}
	if(ansmin==0) ansmin++;
	cout << ansmin << ' ' << ansmax << endl;
	return 0;
}