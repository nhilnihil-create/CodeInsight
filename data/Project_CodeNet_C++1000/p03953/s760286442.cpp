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
#include <nmmintrin.h>
#include <chrono>
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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

struct Edge {
	int from, to;
};

signed main()
{

	int n;
	cin >> n;
	vector<ll> x(n);

	REP(i, n) {
		scanf("%lld", &x[i]);
	}

	ll m, k;
	cin >> m >> k;
	vector<int> w(m);
	REP(i, m) {
		scanf("%d", &w[i]);
		w[i]--;
	}

	vector<vector<int>> sw(65, vector<int>(n-1));
	REP(i, n - 1) {
		sw[0][i] = i;
	}
	REP(i, m) {
		swap(sw[0][w[i] - 1], sw[0][w[i]]);
	}
	rep(cc,1,65){
		REP(i, n-1) {
			sw[cc][i] = sw[cc-1][sw[cc-1][i]];
		}
	}
	vector<int> fn(n - 1);
	REP(i, n - 1) {
		fn[i] = i;
	}
	ll cc = 0;
	ll cl = 1;
	int bai = 0;
	while (cc < k) {
		if (cc + cl <= k) {
			vector<int> nfn(fn);
			REP(i, n - 1) {
				nfn[i] = fn[sw[bai][i]];
			}
			cc += cl;
			cl *= 2;
			bai++;
			fn.swap(nfn);
		}
		else {
			cl /= 2;
			bai--;
		}
	}

	ll cs = x[0];

	cout << x[0] << endl;
	REP(i, n-1) {
		cs = cs + x[fn[i] + 1] - x[fn[i]];
		printf("%lld\n",cs);
	}

	return 0;
}