#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

bool solve(vi os, vi es) {
	bool one = 0;
	for (int x : os) {
		if (x == 1) one = 1;
	}

	if (one) {
		int s = 0;
		for (int x : es) {
			s ^= 1;
		}
		return s;
	}

	if (es.size() % 2 == 1) {
		return 1;
	}

	if (os.size() >= 2) {
		return 0;
	}

	es.pb(os[0] - 1);
	int d = -1;
	for (int x : es) {
		if (d == -1) {
			d = x;
		} else {
			d = __gcd(d, x);
		}
	}

	vi _os, _es;
	for (int x : es) {
		int nx = x / d;
		if (nx & 1) {
			_os.pb(nx);
		} else {
			_es.pb(nx);
		}
	}
	return !solve(_os, _es);
}

int main() {
	int N;
	vi os, es;
	cin >> N;

	rep(i, N) {
		int x;
		cin >> x;
		if (x & 1) {
			os.pb(x);
		} else {
			es.pb(x);
		}
	}

	puts(solve(os, es) ? "First" : "Second");

	return 0;
}