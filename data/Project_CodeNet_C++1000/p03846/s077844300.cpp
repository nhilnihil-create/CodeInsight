#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int modPow(long long a, long long n, long long p) {
	if (n == 1) return a % p;
	if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
	long long t = modPow(a, n / 2, p);
	return (t * t) % p;
}

int res[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	if (n == 1) {
		if (a[0] == 0) dunk(1);
		else dunk(0);
      return 0;
	}

	if (n % 2 == 0) {
		rep(i, n) {
			res[a[i]]++;
		}
		bool elf = true;
		rep(i, n) {
			if (res[i] == 2) {
				if (i % 2 == 0) elf = false;
			}
			else if (res[i] != 0) elf = false;
		}
		if (elf) {
			int ans = modPow(2, n / 2, mod);
			dunk(ans);
		}
		else {
			dunk(0);
		}
	}
	else {
		rep(i, n) {
			res[a[i]]++;
		}
		bool elf = true;
		rep(i, n) {
			if (res[i] == 2) {
				if (i % 2 != 0) elf = false;
			}
			else if (res[i] != 0) {
				if (i != 0) elf = false;
			}
		}
		if (elf) {
			int ans = modPow(2, (n - 1) / 2, mod);
			dunk(ans);
		}
		else {
			dunk(0);
		}
	}

	return 0;
}
