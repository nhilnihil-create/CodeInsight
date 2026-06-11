//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

int n, a[MAXN], ans;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (i == n)
			if (a[i] == i)
				ans++;
			else
				;
		else
			if (a[i] == i)
				swap(a[i], a[i + 1]), ans++;
			else
				;
	}
	cout << ans << endl;
	return 0;
}
