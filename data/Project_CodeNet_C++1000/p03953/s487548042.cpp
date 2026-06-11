#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MN = 101234;
int perm[MN], d[MN], mark[MN], a[MN], ans[MN];

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
		d[i] = a[i + 1] - a[i];
	for (int i = 0; i < n; i++)
		perm[i] = i;
	int m, k;
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		int s;
		cin >> s;
		swap(perm[s - 1], perm[s - 2]);
	}
	for (int i = 0; i < n; i++)
		cerr << perm[i] << '*';
	cerr << endl;
	for (int i = 0; i < n; i++) {
		if (!mark[i]) {
			vector <int> vec;
			int x = perm[i];
			mark[i] = true;
			vec.push_back(i);
			while (x != i) {
				vec.push_back(x);
				mark[x] = true;
				//cerr << x << ' ' << i << endl;
				x = perm[x];
				//cerr << x << ' ' << i << endl;
			}
			for (int i = 0; i < vec.size(); i++)
				ans[vec[i]] = vec[(i + k) % vec.size()];
			//for (int i: vec) 
				//cerr << i << ' ';
			//cerr << endl;
		}
	}
	int sum = a[0];
	for (int i = 0; i < n - 1; i++) {
		cout << sum << ".0" << ' ';
		sum += d[ans[i]];
	}
	cout << sum << ".0" << endl;
}
