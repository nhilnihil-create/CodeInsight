#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	map<int, int> mp;
	rep(i, n) {
		int a;
		cin >> a;
		mp[a]++;
	}
	if (n == 1) {
		for (auto& c : mp) {
			if (c.first == 0) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		return 0;
	}
	if (n % 2 == 0) {
		for (auto& c : mp) {
			if (c.second != 2) {
				cout << 0 << endl;
				return 0;
			}
		}
		ll ans = modPow(2, n / 2, mod);
		cout << ans << endl;
	}
	else {
		for (auto& c : mp) {
			if (c.second != 2) {
				if (!(c.second == 1 && c.first == 0)) {
					cout << 0 << endl;
					return 0;
				}
			}
		}
		ll ans = modPow(2, (n - 1) / 2, mod);
		cout << ans << endl;
	}
	return 0;
}
