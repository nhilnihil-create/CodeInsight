#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	llong N;
	vector<llong> p, pp;

	cin >> N;
	p.resize(N+2), pp.resize(N+1);
	for(int i = 1; i <= N; i++){
		cin >> p[i];
		pp[i] = p[i];
	}

	pp = p;
	llong ans1 = 0, ans2 = 0;
	for(int i = 1; i <= N; i++){
		// for(auto x : p)
		// 	cerr << x << " ";
		// cerr << endl;
		if(i == p[i])
			ans1++, swap(p[i], p[i+1]);
	}
	cerr << endl;

	for(int i = N; i >= 1; i--){
		// for(auto x : pp)
		// 	cerr << x << " ";
		// cerr << endl;
		if(i == pp[i])
			ans2++, swap(pp[i], pp[i-1]);
	}


	cerr << ans1 << " " << ans2 << endl;
	cout << min(ans1,ans2) << endl;

	return 0;
}