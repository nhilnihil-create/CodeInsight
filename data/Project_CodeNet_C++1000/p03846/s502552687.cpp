#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n, a, cnt[100005];
long long ans;

long long binexp(long long x, long long y) {
    long long res = 1;
    x %= MOD;
    while (y) {
        if (y&1) {
        	res = (res * x) % MOD;
        }
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++;
	}

	int odd = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[i] != 0 && cnt[i] != 2 && !(n&1)) {
			cout << 0 << '\n';
			return 0;
		}
		else if (i && (cnt[i]&1) && (n&1)) {
			cout << 0 << '\n';
			return 0;
		}
	}

	if ((n&1) && !(cnt[0]&1)) {
		cout << 0 << '\n';
		return 0;
	}

	cout << binexp(2, n/2) << '\n';
 
	return 0;
}