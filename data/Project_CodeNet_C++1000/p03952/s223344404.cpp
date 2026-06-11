//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 3  * 100 * 1000 + 17;

int n, x, a[MAXN], t = 1;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> x;
	if (x == 2 * n - 1 || x == 1) {
		cout << "No";
		return 0;
	}
	a[n] = x;
	for (int i = n + 1; i <= 2 * n - 1; i++) {
		if (t == x)
			t++;
		a[i] = t;
		t++;
	}
	for (int i = 1; i < n; i++) {
		if (t == x)
			t++;
		a[i] = t, t++;
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= 2 * n - 1; i++)
		cout << a[i] << endl;
	return 0;
}
