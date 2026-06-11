#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MX = 3e5+5;


template<typename T> struct seg_tree {
	T seg[4*MX], tmp[4*MX];
	inline T pull(const T & a, const T & b) { return a+b; }
	inline void push(int l, int r, int n) {
		seg[n] += (r-l+1)*tmp[n];
		if (l != r) tmp[n<<1] += tmp[n], tmp[n<<1|1] += tmp[n];
		tmp[n] = 0;
	}
	void update(int a, int b, T v, int l = 0, int r = MX-1, int n = 1) {
		push(l, r, n);
		if (l > r || l > b || r < a) return;
		if (l >= a && r <= b) { tmp[n] += v, push(l, r, n); return; }
		int m = l+r>>1;
		update(a, b, v, l, m, n<<1), update(a, b, v, m+1, r, n<<1|1);
		seg[n] = pull(seg[n<<1], seg[n<<1|1]);
	}
	T query(int a, int b, int l = 0, int r = MX-1, int n = 1) {
		if (a > b || l > b || r < a) return 0;
		push(l, r, n);
		if (l >= a && r <= b) return seg[n];
		int m = l+r>>1;
		return pull(query(a, b, l, m, n<<1), query(a, b, m+1, r, n<<1|1));
	}
};


ii A[MX];
seg_tree<int> st;

int main() {
	if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N, M; cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> A[i].f >> A[i].s;
	sort(A, A+N, [](auto a, auto b) { return a.s-a.f < b.s-b.f; });

	for (int i = 1, j = 0; i <= M; ++i) {
		while (j < N && A[j].s-A[j].f < i) st.update(A[j].f, A[j].s, 1), ++j;
		int ans = N-j;
		for (int k = 0; k <= M; k += i) ans += st.query(k, k);
		cout << ans << '\n';
	}
}
