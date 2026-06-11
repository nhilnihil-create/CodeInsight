#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int inf = 2e9;
const int N = 105;

int n, a[N], cnt[N];

int main() {
	cin >> n;
	int mn = inf, mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	if (cnt[mn] > 2 || cnt[mx] < 2) return cout << "Impossible", 0;
	int d = cnt[mn] == 1 ? mn * 2 : mn * 2 - 1;
	if (mx != d) return cout << "Impossible", 0;
	for (int i = mn; i <= mx; i++) 
		if (cnt[i] == 0) 
			return cout << "Impossible", 0;
	cout << "Possible";
}
