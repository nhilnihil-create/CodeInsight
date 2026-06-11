#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll, ll> P;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

struct BIT {
	typedef ll input_t;

	vector<input_t> bit_;
	const long long n_;

	BIT(long long n) :n_(n) {
		bit_.resize(n + 1LL, 0);
	}

	input_t sum(int i) {
		input_t s = 0;
		while (i > 0) {
			s += bit_[i];
			i -= i & (-i);
		}
		return s;
	}

	void add(int i, input_t x) {
		while (i <= n_) {
			bit_[i] += x;
			i += (i & (-i));
		}
	}
};


struct BSearch {
	static ll solve(ll left, ll right, function<ll(ll)> pred) {
		while (right - left > 1) {
			ll middle = left + right;
			middle /= 2;
			if (pred(middle)) {
				right = middle;
			}
			else {
				left = middle;
			}
		}
		return right;
	}
};

static ll lpow(ll v, ll c) {
	ll a = 1;
	rep(i, c) {
		a *= v;
	}
	return a;
}

typedef tuple<ll, ll, ll> t3;

static t3 split(ll v) {
	ll x = 0;
	ll y = 0;
	ll c = 0;
	int i = 0;
	while (v > 0) {
		if (v % 3 == 1) {
			x |= 1LL << i;
			c++;
		}
		else if (v % 3 == 2) {
			y |= 1LL << i;
			c++;
		}
		i++;
		v /= 3;
	}
	return { x,y,c };
}

int main() {
	ll h, w, d;
	cin >> h >> w >> d;
	ll d2 = d * 2;
	rep(y, h) {
		rep(x, w) {
			int x2 = x - y + 1000;
			int y2 = x + y + 1000;
			x2 %= d2;
			y2 %= d2;
			if (x2 < d && y2 < d) {
				cout << "R";
			}
			if (x2 >= d && y2 < d) {
				cout << "G";
			}
			if (x2 < d && y2 >= d) {
				cout << "Y";
			}
			if (x2 >= d && y2 >= d) {
				cout << "B";
			}
		}
		cout << endl;
	}
	return 0;
}
