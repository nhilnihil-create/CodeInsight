#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
	int n, k, x, y;
	cin >> n >> k >> x >> y;

	if(n <= k){
		cout << x * n << endl;
	}else{
		cout << (x*k) + (y*(n-k)) << endl;
	}

	return 0;
}
