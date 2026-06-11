 #include <bits/stdc++.h>
 
 using namespace std;
 
 #define int long long
 
 const int N = 1e5 + 5;
 int n, ans[N], a[N];
 vector <pair<int, int>> p;
 
 main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	p.push_back(make_pair(0, n + 1));
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		p.push_back(make_pair(a[i], i));
	}
	sort(p.begin(), p.end()); reverse(p.begin(), p.end());
	int cur = p[0].first, mi = p[0].second;
	int pos = 0, cnt = 1;
	while(cur) {
		while(pos + 1 < n && p[pos + 1].first == cur) {
			++pos; ++cnt;
			mi = min(mi, p[pos].second);
		}
		ans[mi] += (cur - p[pos + 1].first) * cnt;
		cur = p[pos + 1].first;
	} 
	for(int i = 1; i <= n; ++i) cout << ans[i] << '\n';
 }
 