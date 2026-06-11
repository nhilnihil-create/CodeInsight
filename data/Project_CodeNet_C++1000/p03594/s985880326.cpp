#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const string s = "RYGB";

int main () {
    ios_base::sync_with_stdio(0);
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);

	int n, m, d;
	cin >> n >> m >> d;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x = (i + j) % (2 * d);
			int y = (i - j) % (2 * d);
			y = (y + 2 * d) % (2 * d);
			a[i][j] = x / d + 2 * (y / d);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << s[a[i][j]];
		}
		cout << "\n";
	}

	return 0;
}
