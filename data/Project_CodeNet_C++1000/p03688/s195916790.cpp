//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool go(vi a, int x) {
	int u = 0, s = 0;
	for(auto i : a) {
		if(i==x) s++;
		else if(i==x-1) u++;
		else return false;
	}
	if(s==1) return false;
	s/=2;
	return u+(s>0) <= x && x <= u+s;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vi a;
	cin >> n;
	int mx = 0;
	a.resize(n);
	for(auto &i : a) cin >> i, mx = max(mx, i);
	cout << ((go(a, mx)||go(a, mx+1))?"Yes":"No");
}
