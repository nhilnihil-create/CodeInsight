/**
*    author:  boutarou
*    created: 09.06.2020 14:36:43
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define fcout cout << fixed << setprecision(15)
using lint = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const long long MOD = 1e9 + 7;
const long long INF = 3e18;
const double PI = 3.1415926535897932;

class BIT {
private:
	vector<lint>bit;
	int n;
public:
	BIT(int _n) {
		bit.resize(_n + 1);
		rep(i, _n + 1) bit[i] = 0;
		n = _n;
	}

	BIT() {
		n = 0;
	}

	void set(int _n) {
		bit.resize(_n + 1);
		rep(i, _n + 1) bit[i] = 0;
		n = _n;
	}

	int get() {
		return bit.size();
	}

	lint sum(int i) {
		lint s = 0;
		while (i > 0) {
			s += bit[i];
			i -= (i & -i);
		}
		return s;
	}

	lint sum(int i, int j) {
		lint be = sum(i - 1);
		lint af = sum(j);
		return af - be;
	}

	void add(int i, lint x) {
		while (i <= n) {
			bit[i] += x;
			i += (i & -i);
		}
	}
};

int n, k;
int a[200005];
lint sum[200005];
vector<lint>vec;
BIT bit;
lint ans = 0;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
	}
	sum[0] = 0;
	vec.push_back(0);
	rep(i, n) {
		sum[i + 1] = sum[i] + (a[i] - k);
		vec.push_back(sum[i + 1]);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	rep(i, n + 1) {
		sum[i] = lower_bound(vec.begin(), vec.end(), sum[i]) - vec.begin();
	}
	bit.set(vec.size());
	rep(i, n + 1) {
		ans += bit.sum(sum[i] + 1);
		bit.add(sum[i] + 1, 1);
	}
	cout << ans << endl;

	return 0;
}