#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using u32 = uint32_t;
using vi = vector<int>;    using vvi = vector<vi>;
using vb = vector<bool>;   using vvb = vector<vb>;
using vl = vector<ll>;     using vvl = vector<vl>;
using vd = vector<double>; using vvd = vector<vd>;

#define MAXC(c, x) (c = max(c, x))
#define MINC(c, x) (c = min(c, x))

#define REP(i,n) for(auto i = 0 * (n), i##_len = (n); i < i##_len; ++i)
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,s,n) for(ll i=s, i##_len=(ll)(n); i<i##_len; ++i)
#define TEN(x) ((ll)1e##x)
const ll mod = TEN(9) + 7;

int main() {
	#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
	#endif
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(50);
	ll n; cin >> n;
	vl a(n); REP(i, n) cin >> a[i];
	ll sum = 1, num = 0;
	REP(i, n) {
		num++;
		if (a[i] / 2 + a[i] % 2 < num) {
			sum = sum * num % mod;
			num--;
		}
	}
	REP(i, num) {
		sum = sum * (num - i) % mod;
	}
	cout << sum << endl;
}