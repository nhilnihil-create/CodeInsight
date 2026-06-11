#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll N, M, A[100001], seg[400004] = { 0 }, tmp[400004] = { 0 };
void pull(int n) { seg[n] = seg[n << 1] + seg[n << 1 | 1]; }
void push(int l, int r, int n) {
	seg[n] += (r - l + 1) * tmp[n];
	if (l != r) tmp[n << 1] += tmp[n], tmp[n << 1 | 1] += tmp[n];
	tmp[n] = 0;
}
void update(int a, int b, int v, int l = 1, int r = -1, int n = 1) {
	if (r == -1) r = M;
	push(l, r, n);
	if (l > b || r < a) return;
	if (l >= a && r <= b) {
		tmp[n] += v;
		push(l, r, n);
	}
	else {
		int m = (l + r) >> 1;
		update(a, b, v, l, m, n << 1), update(a, b, v, m + 1, r, n << 1 | 1);
		pull(n);
	}
}
ll query(int a, int b, int l = 1, int r = -1, int n = 1) {
	if (r == -1) r = M;
	if (a > b || l > b || r < a) return 0;
	push(l, r, n);
	if (l >= a && r <= b) return seg[n];
	int m = (l + r) >> 1;
	return query(a, b, l, m, n << 1) + query(a, b, m + 1, r, n << 1 | 1);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> A[i];

	ll cnt = 0, sum = 0;
	for (int i = 1; i < N; ++i) {
		if (A[i - 1] < A[i]) {
			sum += A[i] - A[i - 1];
			update(A[i - 1] + 1, A[i] - 1, 1);
			update(A[i], A[i], -(A[i] - A[i - 1] - 1));
		}
		else {
			cnt += M - A[i - 1];
			sum += A[i] - A[i - 1] + M; 
			update(A[i - 1] + 1, M, 1);
			update(1, A[i] - 1, 1);
			update(A[i], A[i], -(A[i] - A[i - 1] + M - 1));
		}
	}
	ll ans = cnt;
	for (int i = 1; i <= M; ++i) {
		cnt += query(i, i);
		ans = max(cnt, ans);
	}
	cout << sum - ans << '\n';
}