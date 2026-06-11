#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> a(n);
	rep (i, 0, n)
		cin >> a[i];

	sort(a.begin(), a.end());
	int kind = 1;
	int count = 0;
	int tmp = a[0];
	rep (i, 1, n) {
		if (a[i] == tmp) {
			count++;
		} else {
			tmp = a[i];
			kind++;
		}
	}

	int res = kind - ((count & 1) ? 1 : 0);
	cout << res << endl;

	return 0;
}
 
