#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t begin = clock();
	int n, m;
	cin >> n >> m;
	vector<int>v(100);
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a]++;
		v[b]++;
	}
	for (int i = 1; i <= n; i++) {
		cout << v[i] << endl;
	}
	clock_t end = clock();
	cerr << "Time run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
}