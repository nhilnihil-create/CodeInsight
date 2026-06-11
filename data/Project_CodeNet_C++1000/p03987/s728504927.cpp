#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


// range query using segment tree
#define ISMAXRANGE	0		// 1 = max range, 0 = min range
#define VERYBIG		200000000	


class segment_tree {
	vector<long long> t;
	long size;
public:
	segment_tree(long n) {
		if (ISMAXRANGE) t.assign(4 * n + 1, 0);
		else t.assign(4 * n + 1, VERYBIG);
		size = n;
	}

	void initialize_array(vector<long long>& v) {
		initialize_with_array(1, 0, size - 1, v);
	}

	void initialize_with_array(long startpos, long l, long r, vector<long long>& v) {
		if (l == r) {
			t[startpos] = v[l];
		}
		else {
			long m = (l + r) / 2;
			initialize_with_array(2 * startpos, l, m, v);
			initialize_with_array(2 * startpos + 1, m + 1, r, v);

			if (ISMAXRANGE == 1) t[startpos] = max(t[startpos * 2], t[startpos * 2 + 1]);
			else  t[startpos] = min(t[startpos * 2], t[startpos * 2 + 1]);
		}
	}

	void update(long index, long long val) { // insert val into location index
		update_full(1, 0, size - 1, index, val);
	}

	void update_full(long startpos, long l, long r, long index, long long val) {
		if (l == r) {
			t[startpos] = val;
		}
		else {
			long m = (l + r) / 2;
			if (index <= m) update_full(2 * startpos, l, m, index, val);
			else update_full(2 * startpos + 1, m + 1, r, index, val);

			if (ISMAXRANGE) t[startpos] = max(t[startpos * 2], t[startpos * 2 + 1]);
			else t[startpos] = min(t[startpos * 2], t[startpos * 2 + 1]);
		}
	}

	long long query(long l, long r) {  // get range min/max between l and r
		if (l > r) {
			if (ISMAXRANGE) return 0;
			else return VERYBIG;
		}
		return query_full(1, 0, size - 1, l, r);
	}

	long long query_full(long startpos, long left, long right, long l, long r) {	 // left/right = current range, l/r = intended query range
		if ((left >= l) && (right <= r)) return t[startpos];
		long m = (left + right) / 2;
		long long ans;
		if (ISMAXRANGE) ans = -(1LL << 60);
		else ans = VERYBIG;
		if (m >= l) {
			if (ISMAXRANGE) ans = max(ans, query_full(startpos * 2, left, m, l, r));
			else ans = min(ans, query_full(startpos * 2, left, m, l, r));
		}
		if (m + 1 <= r) {
			if (ISMAXRANGE) ans = max(ans, query_full(startpos * 2 + 1, m + 1, right, l, r));
			else ans = min(ans, query_full(startpos * 2 + 1, m + 1, right, l, r));
		}
		return ans;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, a, b, c, x, y, ans;
	cin >> n;
	vector<long long> v(n + 2);
	v[0] = 0; v[n + 1] = 0;
	for (i = 1; i <= n; i++) cin >> v[i];

	segment_tree st(n + 2);
	st.initialize_array(v);

	ans = 0;
	for (i = 1; i <= n; i++) {
		a = 0; b = i - 1;
		while (a < b) {
			c = (a + b + 1) / 2;
			if (st.query(c, i - 1) < v[i]) a = c;
			else b = c - 1;
		}
		x = a;

		a = i + 1; b = n + 1;
		while (a < b) {
			c = (a + b) / 2;
			if (st.query(i + 1, c) < v[i]) b = c;
			else a = c + 1;
		}
		y = a;

		ans += (i - x) * (y - i) * v[i];

	}
	cout << ans << "\n";

	return 0;
}

