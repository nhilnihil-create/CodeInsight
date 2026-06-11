//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

int n, a[MAXN], mx, p[MAXN];
ll sum;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sum += a[1] - 1;
	mx = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == mx + 1) {
			mx++;
			continue;
		}
		sum += (a[i] - 1) / (mx + 1);
	}
	cout << sum << endl;
	return 0;
}
