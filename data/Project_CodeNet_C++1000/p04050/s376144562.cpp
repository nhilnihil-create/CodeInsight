//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 + 17;

int n, m, a[MAXN], cnt;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i], cnt += a[i] & 1;
	if (cnt > 2)
		return cout << "Impossible" << endl, 0;
	else if (cnt < 2) {
		if (cnt == 1)
			for (int i = 1; i <= m; i++)
				if (a[i] & 1)
					swap(a[i], a[1]);
		for (int i = 1; i <= m; i++)
			cout << a[i] << ' ';
		cout << endl;
		cout << m + (a[1] > 1) << endl;
		if (a[1] - 1)
			cout << a[1] - 1 << ' ';
		for (int i = 2; i <= m; i++)
			cout << a[i] << ' ';
		cout << 1 << endl;
		return 0;
	}
	else {
		for (int i = 1; i <= m; i++)
			if (a[i] & 1) {
				swap(a[i], a[1]);
				break;
			}
		for (int i = 2; i <= m; i++)
			if (a[i] & 1) {
				swap(a[i], a[m]);
				break;
			}
		for (int i = 1; i <= m; i++)
			cout << a[i] << ' ';
		cout << endl;
		cout << m - (a[1] == 1) << endl;
		if (a[1] - 1)
			cout << a[1] - 1 << ' ';
		for (int i = 2; i < m; i++)
			cout << a[i] << ' ';
		cout << a[m] + 1 << endl;
	}
	return 0;
}
