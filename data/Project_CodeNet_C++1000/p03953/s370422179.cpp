#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " " << x << endl;
#define mid ((s + e) / 2)
long long M = 1e9 + 7;
//>>>>>>>>>>>>>>>>>

const int N = 1e5 + 7;

#define int long long

int x[N], d[N], a[N], p[N], nd[N];
int n, m, k;
bool mrk[N];
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		p[i] = i;
		d[i - 1] = x[i] - x[i - 1];
	}
	cin >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		swap(p[a[i]], p[a[i] - 1]);
	}
	for (int i = 1; i <= n; i++)
	   if (!mrk[i]) {
	   		vector <int> v;
			int t = i;
			int sv = i;
			do {
				v.push_back(t);
				mrk[t] = 1;
				t = p[t];
			} while (sv != t);
			for (int j = 0; j < v.size(); j++) {
				nd[v[j]] = d[v[(j + k) % v.size()]];
			}
	   }	   
	cout << x[1] << ".0" << '\n';
	for (int i = 2; i <= n; i++) {
		x[i] = x[i - 1] + nd[i - 1];
		cout << x[i] << ".0" << '\n';
	}




}
