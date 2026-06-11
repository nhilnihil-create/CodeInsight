#pragma comment(linker, "/STACK:32000000")
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, _= (n); i < _; ++i)
#define DWN(i, n) for (int i = (n) - 1; i >= 0; --i)
#define FOR(i, l, r) for (int i = (l), _ = (r); i < _; ++i)
#define EDGE(u, v, e) for (int e = head[u], v; e != nil && (v = to[e], true); e = next[e])

using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef complex<double> comp;

inline bool read(int& val)    { return scanf("%d",    &val) != -1;}
inline bool read(int64& val)  { return scanf("%I64d", &val) != -1;}
inline bool read(double& val) { return scanf("%lf",   &val) != -1;}
inline bool read(char* val)   { return scanf("%s",     val) != -1;}
template<class T1, class T2>
inline bool read(T1& a, T2& b)
{ return read(a) && read(b); }
template<class T1, class T2, class T3>
inline bool read(T1& a, T2& b, T3& c)
{ return read(a) && read(b) && read(c); }
template<class T1, class T2, class T3, class T4>
inline bool read(T1& a, T2& b, T3& c, T4& d)
{ return read(a) && read(b) && read(c) && read(d); }
template<class T1, class T2, class T3, class T4, class T5>
inline bool read(T1& a, T2& b, T3& c, T4& d, T5& e)
{ return read(a) && read(b) && read(c) && read(d) && read(e); }

const int nil = -1;
const int N = 211111;

long long val[N];
char op[N][3];

int main() {
//	freopen("test.txt", "r", stdin);
	int n; read(n);
	cin >> val[0];
	FOR (i, 1, n) cin >> op[i] >> val[i] ;
	long long sum = val[0];
	FOR (i, 1, n) {
		if (op[i][0] == '+') sum += val[i];
		if (op[i][0] == '-') sum -= val[i];
	}

	long long plus = 0, cost = 0;
	long long ans = sum;
	for (int i = n - 1; i > 0; i--) {
		if (op[i][0] == '+') cost += 2 * val[i];
		if (op[i][0] == '-') {
			ans = max(ans, sum + plus - cost);
			plus += 2 * val[i];
			cost = 0;
		}
	}
	cout << ans << endl;
	return 0;
}

