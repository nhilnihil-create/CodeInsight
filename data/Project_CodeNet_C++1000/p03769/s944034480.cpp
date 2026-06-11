#include <bits/stdc++.h>

using namespace std;

#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)

#define LL long long
#define mp make_pair
#define pb push_back

LL n;

pair<vector<int>, vector<int> > solve(LL d, int deg) {
	if (d == 0) {
		vector<int> x, y;
		x.clear(); y.clear();
		return mp(x, y);
	}

	if (d == 1) {
		vector<int> x, y;
		x.clear(); y.clear();
		x.pb(deg); y.pb(deg);
		return mp(x, y);
	}
	
	if (d % 2) {
	
		pair<vector<int>, vector<int> > ret = solve(d / 2, deg + 1);
		
		ret.first.pb(deg); ret.second.pb(deg);
		return ret;	
	} else {
		pair<vector<int>, vector<int> > ret = solve(d - 1, deg + 1);
		ret.first.pb(deg); ret.second.insert(ret.second.begin(), deg); 	
		
		return ret;
	}
}

int main(){
	cin >> n;
	
	pair<vector<int>, vector<int> > V = solve(n, 1);
	
	int sum = V.first.size() + V.second.size();
	
	printf("%d\n", sum);
	
	FOR(i, 0, V.first.size()) printf("%d ", V.first[i]);
	
	FOR(i, 0, V.second.size()) printf("%d%c", V.second[i], (i == V.second.size() - 1 ? '\n': ' '));
}