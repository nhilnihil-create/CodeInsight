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
template<typename H> void print(H head) { cout << head << endl; }
template<typename H, typename ...T> void print(H head, T ...tail) { cout << head << " "; print(tail...); }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, c, k; read(n, c, k);
	vector<int> v(n);
	rep(i, 0, n) read(v[i]);

	sort(all(v));

	int st = 0, ans = 1;
	rep(i, 1, n) {
		if (i - st >= c || v[i] - v[st] > k) {
			st = i;
			ans++;
		}
	}

	print(ans);
}
