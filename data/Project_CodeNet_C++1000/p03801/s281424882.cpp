#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector< pair<int, int> >
const int inf = 1e9 + 7;
bool cmp(ii a, ii b) {
	if (a.first != b.first)
		return a.first > b.first;
	else
		return a.second < b.second;
}
signed main() {
	int n, sum = 0;
	cin >> n;
	vii a(n + 1);
	vi ans(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	a[0] = make_pair(inf, 0);
	sort(a.begin(), a.end(), cmp);
	ii tmp = a[1];
	sum = tmp.first;
	for (int i = 2; i <= n; i++) {
		if (a[i].first < tmp.first) {
			ans[tmp.second] += sum - a[i].first * (i - 1);
			sum = a[i].first * i;
			if (a[i].second < tmp.second)
				tmp = a[i];
			else
				tmp.first = a[i].first;
		}
		else
			sum += a[i].first;
	}
	ans[tmp.second] += sum;
	for(int i = 1; i <= n; i++) 
		cout << ans[i] << endl;
}