#include <bits/stdc++.h>
using namespace std;
void err() {
	cout << "NO" << endl;
	exit(0);
}
inline bool chmax (int& a, int b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
vector<int> a;
void dfs (
	int crr
, int prt
, vector<int>& out
, vector<vector<int>>& grh
) {
	int cnt = 0;
	int in = 0;
	int mxv = 0;
	for (int nxt : grh[crr]) if (nxt != prt) {
		cnt++;
		dfs(nxt, crr, out, grh);
		in += out[nxt];
		chmax(mxv, out[nxt]);
	}
	if (cnt) {
		out[crr] = in - 2 * (in - a[crr]);
	} else {
		out[crr] = a[crr];
	}
	if (out[crr] < max(0, 2 * mxv - in) || a[crr] < out[crr]) err();
	if (crr == 0 && 
		(
			(cnt == 1 && a[0] != out[0]) ||
			(cnt > 1 && out[0] != 0)
		)
	) {
		err();
	}
}
int main() {
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int>> grh(n);
	for (int i = 0; i < n - 1; i++) {
		int s, t;
		cin >> s >> t;
		grh[--s].push_back(--t);
		grh[t].push_back(s);
	}
	vector<int> out(n, -1);
	dfs(0, 0, out, grh);
	cout << "YES" << endl;
	return 0;
}