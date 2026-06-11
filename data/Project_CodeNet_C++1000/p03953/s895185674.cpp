#include <bits/stdc++.h>
using namespace std;

using f64 = double;
using i64 = long long;

vector<i64> a, ans, pos, perm;
i64 k;
int n, m;

static vector<i64> join(vector<i64> &a, vector<i64> &b) {
	vector<i64> res(a.size());
	for (int i = 0; i < res.size(); ++i)
		res[i] = a[b[i]];

	return res; }

static void exp(vector<i64> &p, i64 e) {
	vector<i64> aux, ans(p.size());
	
	aux = p;
	iota(begin(ans), end(ans), 0);
	for (; e > 0; e/= 2) {
		if (e % 2)
			ans = join(ans, aux);
		aux = join(aux, aux); }

	p = ans; }

int main() {
#ifdef HOME
	freopen("agc6c.in", "r", stdin);
	freopen("agc6c.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	pos.resize(n), for_each(begin(pos), end(pos), [&](i64 &x) { cin >> x; });
	cin >> m >> k;
	a.resize(m), for_each(begin(a), end(a), [&](i64 &x) { cin >> x; });

	perm.resize(n - 1);
	iota(begin(perm), end(perm), 0);
	for (int i = 0; i < m; ++i)
		swap(perm[a[i] - 1], perm[a[i] - 2]);

	exp(perm, k);

	ans.resize(n);
	ans[0] = pos[0];
	for (int i = 0; i < n - 1; ++i)
		ans[i + 1]+= pos[perm[i] + 1] - pos[perm[i]];

	for (int i = 1; i < n; ++i)
		ans[i]+= ans[i - 1];

	for (int i = 0; i < n; ++i)
		cout << ans[i] << ".0\n";

	return 0; }
