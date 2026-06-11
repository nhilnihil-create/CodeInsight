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
template<typename H> void print(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void print(H head, T ...tail) { cout << head << " "; print(tail...); }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m, k; read(n, m, k);
	bool ok = 0;
	rep(i, 0, n + 1) rep(j, 0, m + 1) if (i * m + j * n - i * j * 2 == k) ok = 1;
	print(ok ? "Yes" : "No");
}
