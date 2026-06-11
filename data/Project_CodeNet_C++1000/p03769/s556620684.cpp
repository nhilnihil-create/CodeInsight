// Why am I so dumb? :c
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

vector<int> vv;

ll n;

void rec(ll x, int cur = 100) {
	if (x == 1) {
		return;
	}

	if (x & 1) {
		rec(x - 1, cur - 1);
		vv.insert(vv.begin(), cur);
	}
	else {
		rec(x / 2, cur - 1);
		vv.pb(cur);		       		
	}
}

void solve() {
	scanf("%lld", &n);
	rec(n + 1);

	for (int i = 1; i <= 100; ++i) {
		vv.pb(i);
	}

	printf("%d\n", vv.size());

	for (int i = 0; i < vv.size(); ++i) {
		printf("%d", vv[i]);
		printf(i + 1 == vv.size() ? "\n" : " ");
	}                 
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}