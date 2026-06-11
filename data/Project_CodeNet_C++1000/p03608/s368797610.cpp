#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<int>> c(n, vector<int>(n));
	rep(i, n) rep(j, n) c.at(i).at(j) = 1000000000;
	rep(i, n) c.at(i).at(i) = 0;
	vector<int> zi(r);
	rep(i, r){
		cin >> zi.at(i);
		zi.at(i)--;
	}
	rep(i, m){
		int a, b, cos;
		cin >> a >> b >> cos;
		a--; b--;
		c.at(a).at(b) = cos;
		c.at(b).at(a) = cos;
	}
	rep(k, n) rep(i, n) rep(j, n){
		c.at(i).at(j) = min(c.at(i).at(j), c.at(i).at(k) + c.at(k).at(j));
	}
	sort(zi.begin(), zi.end());
	ll ans = 2000000000000000000;
	do{
		ll sum = 0;
		rep(i, r-1) sum += c.at(zi.at(i)).at(zi.at(i+1));
		if(sum < ans) ans = sum;
	}while(next_permutation(zi.begin(), zi.end()));
	cout << ans << endl;
	return 0;
}