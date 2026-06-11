#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))

vector<int> parser(const string& s) {
	const int N = s.size();
	vector<int> res(N + 1, 0);
	rep(i, N)res[i + 1] = s[i] == 'A' ? 1 : 2;
	rep(i, N)res[i + 1] += res[i];
	return res;
}

int main()
{
	string s, t;
	int q;
	cin >> s >> t >> q;

	auto imoss = parser(s);
	auto imost = parser(t);

	rep(i, q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; c--;

		int ps = (imoss[b] - imoss[a]) % 3;
		int pt = (imost[d] - imost[c]) % 3;
		cout << (ps == pt ? "YES" : "NO") << endl;
	}

	return 0;
}
