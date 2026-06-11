#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 102030;
string S[2];
int pref[2][MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	FOR(i, 0, 1) {
		cin >> S[i];
		pref[i][0] = 0;
		FOR(j, 0, SZ(S[i]) - 1) pref[i][j + 1] = pref[i][j] + (S[i][j] - 'A' + 1);
	}
	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << ((pref[0][b] - pref[0][a - 1]) % 3 == (pref[1][d] - pref[1][c - 1]) % 3 ? "YES" : "NO") << endl;
	}

	return 0;
}
