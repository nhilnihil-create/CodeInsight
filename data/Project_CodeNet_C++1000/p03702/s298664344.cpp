#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define int long long
using namespace std;

int n, a, b;
vector<int> h; 

bool f(int m){
	int cnt = 0;
	rep(i, 0, n){
		int tmp = h[i] - b * m;
		if(tmp >= 0) cnt += (tmp + a - b - 1) / (a - b);
	}
	return cnt <= m;
}

signed main(){
	cin >> n >> a >> b;
	h.resize(n);
	rep(i, 0, n){
		cin >> h[i];
	}
	int ng = 0, ok = 1e9;
	while(ok - ng > 1){
		int mid = (ok + ng) / 2;
		if(f(mid)) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}