#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	llong N, K;
	vector<llong> A, rui, prui;

	cin >> N >> K;
	A.resize(N+1);
	rui.resize(N+1,0);
	prui.resize(N+1,0);
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		rui[i] = rui[i-1] + A[i];
		prui[i] = prui[i-1] + (A[i] > 0 ? A[i] : 0);
	}

	llong ans = 0;
	for(int i = 1; i <= N-K+1; i++){
		llong res = prui[i-1] - prui[0] + prui[N] - prui[i+K-1];
		ans = max({ans,res, res + rui[i+K-1] - rui[i-1]});
	}

	cout << ans << endl;

	return 0;
}