// Why am I so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)1e5 + 5;

pair<ll, int> arr[MAXN];

pair<ll, int> pt[MAXN];

ll col[MAXN];

ll ans[MAXN];

ll m, lim;

int n;

void solve() {                   
	scanf("%d %lld %lld", &n, &m, &lim);

	for (int i = 0; i < n; ++i) {
		scanf("%lld %d", &arr[i].fi, &arr[i].se);

		if (arr[i].se == 2) {
			arr[i].se = -1;
		}
	}

	for (int i = 0; i < n; ++i) {
		pt[i] = mp(arr[i].fi + arr[i].se * lim, i);
		pt[i].fi = (pt[i].fi % m + m) % m;
	}

	sort(pt, pt + n);
	ll one = 0;
	int p = 0;

	for (int i = 1; i < n; ++i) {
		if (arr[i].se == arr[0].se) {
			continue;
		}

		if (arr[0].se == 1) {
		    ll t = arr[i].fi - arr[0].fi;

		    if (t <= lim * 2) {
		    	ll add = ((2ll * lim - t) / m + 1ll) % n;
				one = ((one + add) % n + n) % n;
            }
		}
		else {
			ll t = arr[0].fi - arr[i].fi + m;

			if (t <= lim * 2) {
				ll add = ((2ll * lim - t) / m + 1ll) % n;
				one = ((one - add) % n + n) % n;
			}
		}
	}

    for (int i = 0; i < n; ++i) {
    	if (pt[i].se == 0) {
    		p = i;
    		break;
    	}
    }

    if (pt[p].fi == pt[(p + 1) % n].fi) {
    	if (arr[0].se == 1) {
    		p = (p + 1) % n;
    	}
    }

    for (int i = 0; i < n; ++i) {
    	col[(p + i) % n] = (one + i) % n;
    }

    for (int i = 0; i < n; ++i) {
    	ans[col[i]] = pt[i].fi;
    }

    for (int i = 0; i < n; ++i) {
    	printf("%lld\n", ans[i]);
    }
}

int main() {    
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}