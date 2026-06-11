#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> g;
vector<vector<int>> ec;
vector<vector<int>> vc;
vector<vector<int>> vd;
int n;

int f(int x, int l, int sum){
	sum++;
	rep(i, g.at(l).size()){
		vc.at(x).at(g.at(l).at(i)) = min(vc.at(x).at(l) + ec.at(l).at(i), vc.at(x).at(g.at(l).at(i)));
	}
	int mi = 2000000001;
	int k = 0;
	rep(i, n){
		if(vc.at(x).at(i) < mi && vd.at(x).at(i) == 0){
			mi = vc.at(x).at(i);
			k = i;
		}
	}
	vd.at(x).at(k) = 1;
	if(sum != n) f(x, k, sum);
	return 0;
}

int main(){
	int m, r;
	cin >> n >> m >> r;
	g = vector<vector<int>>(n, vector<int>(0));
	ec = vector<vector<int>>(n, vector<int>(0));
	vc = vector<vector<int>>(n, vector<int>(n));
	vd = vector<vector<int>>(n, vector<int>(n));
	vector<int> zi(r);
	rep(i, n) rep(j, n){
		vc.at(i).at(j) = 2000000000;
		vd.at(i).at(j) = 0;
	}
	rep(i, n){
		vc.at(i).at(i) = 0;
		vd.at(i).at(i) = 1;
	}
	rep(i, r){
		cin >> zi.at(i);
		zi.at(i)--;
	}
	rep(i, m){
		int a, b, cos;
		cin >> a >> b >> cos;
		a--; b--;
		g.at(a).push_back(b);
		g.at(b).push_back(a);
		ec.at(a).push_back(cos);
		ec.at(b).push_back(cos);
	}
	rep(i, n){
		f(i, i, 1);
	}
	sort(zi.begin(), zi.end());
	ll ans = 2000000000000000000;
	do{
		ll sum = 0;
		rep(i, r-1) sum += vc.at(zi.at(i)).at(zi.at(i+1));
		if(sum < ans) ans = sum;
	}while(next_permutation(zi.begin(), zi.end()));
	cout << ans << endl;
	return 0;
}