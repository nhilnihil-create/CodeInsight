#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))

int reach(const vector<vector<int>>& db, int day, int now) {
	int e = 0;
	while (day > 0) {
		if (day & 1)now = db[e][now];
		e++;
		day >>= 1;
	}
	return now;
}

int main()
{
	int N, L, Q;
	cin >> N;
	vector<int> x(N);
	rep(i, N)cin >> x[i];
	cin >> L >> Q;

	const int D = log2(N) + 1;
	vector<vector<int>> db(D, vector<int>(N));
	rep(i, N)db[0][i] = upper_bound(x.begin(), x.end(), x[i] + L) - x.begin() - 1;
	rep(d, D - 1)rep(i, N) {
		int next = db[d][i];// 2^d
		db[d + 1][i] = db[d][next];// 2^d + 2^d
	}

	// output
	rep(i, Q) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (a > b)swap(a, b);

		int l = 0, r = N;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (b <= reach(db, mid, a))r = mid;
			else l = mid;
		}
		cout << r << endl;
	}

	return 0;
}
