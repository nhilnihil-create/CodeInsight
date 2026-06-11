#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", x);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep (i, n) cin >> a[i] >> b[i];

	ll ans = 0;
	ll sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		a[i] += sum;
		if (a[i] % b[i] == 0) continue;
		else if (a[i] < b[i]) {
			ans += b[i] - a[i];
			sum += b[i] - a[i];
		}
		else {
			ans += b[i] - a[i] % b[i];
			sum += b[i] - a[i] % b[i];
		}
	}

	cout << ans << endl;
	return 0;
}