#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e9)+7;
const llong mod = 1e9+7;

int main(){
	llong N, A, B;
	vector<llong> h;

	cin >> N >> A >> B;
	h.resize(N);
	llong maxi = 0;
	for(int i = 0; i < N; i++){
		cin >> h[i];
		maxi = max(maxi, h[i]);
	}

	llong ng = 0, ok = inf;
	while(abs(ng - ok) > 1){
		llong middle = (ng+ok+1)/2;
		llong ans = 0;
		for(int i = 0; i < N; i++){
			llong check = max(0ll, h[i] - B*middle);
			ans += check/(A-B) + (check%(A-B) ? 1 : 0);
		}
		// cerr << middle << " " << ans << endl;
		if(ans <= middle)
			ok = middle;
		else
			ng = middle;
	}

	cout << ok << endl;

	return 0;
}