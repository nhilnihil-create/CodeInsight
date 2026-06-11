// Why am I so dumb? :c
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)1e5 + 5;

pair<int, int> arr[MAXN];

pair<int, int> fc[MAXN];

int ans[MAXN];

int n, m, t;

void solve() {
	scanf("%d %d %d", &n, &m, &t);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &arr[i].fi, &arr[i].se);

		if (arr[i].se == 2) {
			arr[i].se = -1;
		}

		fc[i] = mp(((arr[i].fi + arr[i].se * t) % m + m) % m, i);		
	}

	sort(fc, fc + n);    

	int cur = 0;

	for (int i = 1, x; i < n; ++i) {
		if (arr[i].se == arr[0].se) {
			continue;
		}

		if (arr[0].se == 1) {
			x = (arr[i].fi - arr[0].fi + m) % m;		
		}
		else {
			x = (arr[0].fi - arr[i].fi + m) % m;
		}

		if (x <= t * 2) {
			int k = (t * 2 - x) / m + 1;
			cur = ((cur + k * arr[0].se) % n + n) % n;
		}	
	}

	int ps = 0;

	for (int i = 0; i < n; ++i) {
		if (fc[i].se == 0) {
			ps = i;
		}
	}

	if (fc[(ps + 1) % n].fi == fc[ps].fi && arr[0].se == 1) {
		ps = (ps + 1) % n;
	}

	for (int i = 0; i < n; ++i) {
		ans[(cur + i) % n] = fc[(ps + i) % n].fi;
	}

	for (int i = 0; i < n; ++i) {
		printf("%d\n", ans[i]);
	}
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}