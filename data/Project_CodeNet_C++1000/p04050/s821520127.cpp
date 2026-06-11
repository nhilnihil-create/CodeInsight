#include <bits/stdc++.h>

#define sqr(A) ((A) * (A))
#define F first
#define S second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;

const int N = 1e2 + 20;
int a[N], n, b[N], m, odd;
vector<int> ans;

bool cmp(int x, int y) {
	if (x % 2 != y % 2)
		return x % 2 < y % 2;
	return x < y;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		odd += a[i] % 2;
	}
	if (m == 1) {
		cout << a[0] << endl;
		if (a[0] == 1) {
			cout << 1 << endl;
			cout << 1 << endl;
		}
		else {
			cout << 2 << endl;
			cout << a[0] - 1 << ' ' << 1 << endl;
		}
		return 0;
	}
	if (odd > 2)
		return cout << "Impossible" << endl, 0;
	sort(a, a + m, cmp);
	if (odd == 2)
		swap(a[m - 2], a[0]);
	for (int i = 0; i < m; i++)
		cout << a[i] << ' ';
	cout << endl;
	if (a[0] == 1) {
		cout << m - 1 << endl;
		for (int i = 1; i < m - 1; i++)
			cout << a[i] << ' ';
		cout << a[m - 1] + 1 << endl;
	}
	else {
		cout << m << endl;
		cout << a[0] - 1 << ' ';
		for (int i = 1; i < m - 1; i++)
			cout << a[i] << ' ';
		cout << a[m - 1] + 1 << endl;
	}
}