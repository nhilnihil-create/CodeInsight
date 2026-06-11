#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using vi = vector<int>;
using ll = long long;
const int maxn = 505, mod = 924844033;
int n, a[maxn], ans[maxn*maxn];
vector<pair<int, int>> add[maxn*maxn];
multiset<pair<int, int>> x;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(ans[a[i]]) return cout << "No", 0;
		ans[a[i]] = i;
		for(int j = 1; j < i; j++) add[1].pb({a[i], i});
		for(int j = i; j < n; j++) add[a[i]].pb({1<<30, i});
	}
	for(int i = 1; i <= n*n; i++) {
		for(auto j : add[i]) x.insert(j);
		if(ans[i]) continue;
		if(x.empty()) return cout << "No", 0;
		ans[i] = x.begin()->second;
		x.erase(x.begin());
	}
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		for(int j = 1; j <= a[i]; j++) {
			cnt += ans[j] == i;
		}
		if(cnt != i) return cout << "No", 0;
	}
	cout << "Yes\n";
	for(int i = 1; i <= n*n; i++) cout << ans[i] << " ";
}
