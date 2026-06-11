#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#define dlog(str) cout << "====" << str << endl;
#else
#define dlog(str)
#endif
#define INF 999999999
#define MOD 1000000007
#define REP(i, n) for(int i = 0, i##_l = (n); i < i##_l; i++)
#define FOR(i, s, e) for(int i = s, i##_l = (e); i < i##_l; i++)
#define LLI long long int
#define _min(a,b) ((a<b)?a:b)
#define _max(a,b) ((a<b)?b:a)
#define chmax(a, b) a = _max(a, b)
#define chmin(a, b) a = _min(a, b)
#define bit(a, shift) ((a>>shift)&1))
#define pm(a) ((a)?1:-1)
#define SORT(v) sort(v.begin(),v.end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
// int 2.14E±9    lli 9.2E±18    double 1.7E±380

LLI power(LLI a, LLI b) { LLI res = 1; while (b > 0) { if (b & 1)res = res * a; a = a * a; b >>= 1; }return res; }

#define PAS_SIZE 60
LLI pas[PAS_SIZE][PAS_SIZE];
int main() {


	pas[0][0] = 1;
	for (int i = 1; i < PAS_SIZE; i++) {
		for (int j = 1; j < PAS_SIZE; j++) {
			pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}




	cout << fixed << setprecision(10);
	int n, a, b;
	cin >> n >> a >> b;
	vector<LLI> v(n);
	REP(i, n)cin >> v[i];
	RSORT(v);

	// 平均の最大
	double sum = 0;
	REP(i, a)sum += v[i];
	double ave = sum / a;

	cout << ave << endl;

	// 組み合わせ
	int cnt = 0;
	REP(i, n)if (v[a - 1] == v[i])cnt++;
	int useA = 0;
	REP(i, a)if (v[a - 1] == v[i])useA++;
	int useB = 0;
	REP(i, b)if (v[a - 1] == v[i])useB++;


	LLI ans = 0;
	if (v[0] == v[a - 1]) {
		for (int i = useA; i <= useB; i++) {
			ans += pas[cnt + 1][i + 1];
		}
	}
	else {
		ans = pas[cnt + 1][useA + 1];
	}
	cout << ans;
	return 0;
}

/*
1125899906842623
19898961463

*/