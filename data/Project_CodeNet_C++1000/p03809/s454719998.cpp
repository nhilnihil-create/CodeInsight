#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <bitset>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int

#include <nmmintrin.h>
#ifdef _MSC_VER

#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

struct Edge {
	int from, to;
};

int main() {
	int n, root = 0;
	cin >> n;
	vector<ll> num(n), cn(n);
	vector<vector<Edge>> g(n);
	REP(i, n) {
		scnaf("%lld", &num[i]);
		cn[i] = num[i];
	}
	REP(i, n-1) {
		int a, b;
		scnaf("%d %d", &a, &b);
		a--, b--;
		g[a].push_back({ a,b });
		g[b].push_back({ b,a });
		if (g[a].size() > 1) root = a;
		if (g[b].size() > 1) root = b;
	}

	if (n == 2) {
		if (cn[0] == cn[1]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return 0;
	}

	function<ll(int, int)> imo = [&](int c, int p) {
		ll sum = 0;
		if (g[c].size() == 1) {
			sum = num[c];
		}
		for (auto itr : g[c]) {
			if (itr.to == p) continue;
			sum += imo(itr.to, c);
		}
		cn[c] -= sum;
		return sum;
	};

	imo(root, -1);

	function<pll(int, int)> dfs = [&](int c, int p) {
		ll es = 0;

		if (g[c].size() == 1) {
			return make_pair( num[c], 0LL );
		}
		vector<ll> up;
		for (auto itr : g[c]) {
			if (itr.to == p) continue;
			pll cc;
			cc = dfs(itr.to, c);
			up.push_back(cc.first);
			es += cc.second;
			cn[c] += cc.second * 2;
		}
		ll be = -cn[c];
		ll en = -cn[c], mt = 0;
		if(be < 0) {
			cout << "NO" << endl;
			exit(0);
		}
		ll mx = 0, sm = 0;
		for (auto itr : up) {
			mx = max(mx, itr);
			sm += itr;
		}
		if (mx > sm / 2)
			mx = sm - mx;
		else
			mx = sm/2;

		if (mx < be) {
			cout << "NO" << endl;
			exit(0);
		}

		mt = sm - be * 2;

		return MP(mt, es + be);
	};

	pll ret = dfs(root, -1);

	if (ret.first != 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}


	return 0;
}