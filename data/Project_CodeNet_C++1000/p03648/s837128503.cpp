#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-12;

template <typename T> void dump(T x) { cout << x << endl; }
void dumpf(ld x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}

inline ll mod(ll a, ll b) {
	if (a > 0) return a % b;
	if (a % b == 0) return 0;
	ll x = -a / b + 1;
	a += x * b;
	return a % b;
}

// ll dx[4] = {1, 0, -1, 0};
// ll dy[4] = {0, 1, 0, -1};

int main() {
	IOS();
	ll k;
	cin >> k;
	vector<ll> a(50);
	for (int i = 0; i < 50; i++) {
		a[i] = i;
	}
	ll t = k % 50;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 50; j++) {
			if (i == j)
				a[j] += 50;
			else
				a[j]--;
		}
	}
	for (int i = 0; i < 50; i++) {
		a[i] += k / 50;
	}
	dump(50);
	for (int i = 0; i < 50; i++) {
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl;
}