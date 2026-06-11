#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s; cin >> s;
	int n = sz(s);
	vector<int> v(n);
	for (int i = n - 1; i >= 0; i--) {
		v[i] = s.back() - '0';
		s.pop_back();
	}

	ll sum = 0;
	for (int i = 0; i < (1 << (n - 1)); i++) {
		ll cur = 0;
		for (int j = 0; j < n; j++) {
			cur = cur * 10 + v[j];
			if (i & (1 << j)) {
				sum += cur;
				cur = 0;
			}
		}
		sum += cur;
	}

	die(sum);
}
