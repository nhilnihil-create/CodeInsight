#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

int N, M;
int X[100000];
vector<int> md[100000];
vector<pair<int, int>> md2[100000];

int main(int argc, char **argv) {
	cin >> N >> M;
	REP(i, N) {
		cin >> X[i];
		md[X[i] % M].push_back(X[i]);
	}
	REP(i, M) {
		sort(ALL(md[i]));
		int p = -1, cnt = 0;
		REP(j, md[i].size()) {
			if (md[i][j] != p) {
				if (cnt != 0) {
					md2[i].push_back(MP(p, cnt));
				}
				p = md[i][j];
				cnt = 0;
			}
			++cnt;
		}
		if (cnt != 0) md2[i].push_back(MP(md[i][md[i].size() - 1], cnt));
	}
	int res = md[0].size() / 2;
	FOR(i, 1, (M - 1) / 2 + 1) {
		int a = 0, b = 0;
		while (true) {
			while (a < md2[i].size() && md2[i][a].second % 2 == 0) ++a;
			while (b < md2[M - i].size() && md2[M - i][b].second % 2 == 0) ++b;
			if (a >= md2[i].size()) {
				int k = 0;
				while (b < md2[M - i].size()) {
					while (k < md2[i].size() && md2[i][k].second == 0) ++k;
					if (k == md2[i].size()) break;
					--md2[i][k].second; --md2[M - i][b].second;
					++res;
					while (b < md2[M - i].size() && md2[M - i][b].second % 2 == 0) ++b;
				}
				break;
			}
			if (b >= md2[M - i].size()) {
				int k = 0;
				while (a < md2[i].size()) {
					while (k < md2[M - i].size() && md2[M - i][k].second == 0) ++k;
					if (k == md2[M - i].size()) break;
					--md2[i][a].second; --md2[M - i][k].second;
					++res;
					while (a < md2[i].size() && md2[i][a].second % 2 == 0) ++a;
				}
				break;
			}
			--md2[i][a].second; --md2[M - i][b].second;
			++res;
		}
		REP(j, md2[i].size()) res += md2[i][j].second / 2;
		REP(j, md2[M - i].size()) res += md2[M - i][j].second / 2;
	}
	if (M % 2 == 0) {
		int a = 0, b = 0;
		while (true) {
			while (a < md2[M / 2].size() && md2[M / 2][a].second % 2 == 0) ++a;
			b = a + 1;
			while (b < md2[M / 2].size() && md2[M / 2][b].second % 2 == 0) ++b;
			if (b >= md2[M / 2].size()) break;
			--md2[M / 2][a].second; --md2[M / 2][b].second;
			++res;
		}
		REP(j, md2[M / 2].size()) res += md2[M / 2][j].second / 2;
	}
	cout << res << endl;
	return 0;
}
