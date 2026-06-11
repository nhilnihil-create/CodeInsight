#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) < (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007LL
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589


#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}
pll Dir[8] = { //移動
	{ 0 ,1 },{ -1 ,0 },{ 1 ,0 },{ 0 ,-1 },
	{ 1 ,1 },{ 1 ,-1 },{ -1 ,1 },{ -1 ,-1 }
};

//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define INF 10000000000000000LL

struct Edge {
	int from, to;
	ll w;
};
typedef vector<vector<Edge>> Graph;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}


bool BellmanFord(Graph g, int s, vector<ll>& dis) { //is huheiro aru
#define INF 10000000000000LL
	fill(ALL(dis), INF);
	dis[s] = 0;
	REP(cc, g.size()*10) {

		REP(v, g.size()) {
			for (auto e : g[v]) {
				if (cc >= g.size() && e.to == g.size()-1 && dis[e.to] > dis[e.from] + e.w) return 1;
				dis[e.to] = min(dis[e.to], dis[e.from] + e.w);
			}
		}

	}


	return 0;
}

signed main(void) {
	ll n, m;
	cin >> n >> m;

	vector<ll> x(n), y(m);

	REP(i, n) {
		cin >> x[i];
	}

	REP(j, m) {
		cin >> y[j];
	}

	ll A = 0, B = 0, C = 0,D = 0, E= 0;

	rep(i, 1, m + 1) {
		(B += y[i-1])%=MODU;
		(C += i * y[i-1])%= MODU;

		(A += y[i-1] * (i - 1))%= MODU;
	}
	rep(i, 1, n + 1) {
		(D += x[i - 1] * (i - 1)) %= MODU;
		(E += (n - i) * x[i - 1]) %= MODU;
	}
	cout << ((((A - m * B + C)%MODU) * (D - E) % MODU) + MODU)%MODU << endl;
	return 0;
}

