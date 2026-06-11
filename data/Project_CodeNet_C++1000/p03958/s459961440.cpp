#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (int)(n); i++)
#define rep2(i,x,n) for(int i = (int)x; i < (int)(n); i++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int k, t, mx = 0;
	cin >> k >> t;
	vector<int> a(t);
	rep(i, t){
		cin >> a.at(i);
		mx = max(a.at(i), mx);
	}

	if(mx <= k/2) cout << 0 << endl;
	else cout << mx - (k-mx) - 1 << endl;

	return 0;
}