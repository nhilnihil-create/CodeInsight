#include <iostream>
#include <array>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <queue>
#include <iomanip>
#include <functional>
#include <climits>
#include <tuple>
#include <unordered_map>
#include <limits>
#include <functional>
#include <cassert>
#include <numeric>
#include <bitset>
#include <set>

#define FOR(x,n) for(int x = 0; x < n; x++)
#define INPUT(x) scanf("%d",&x)
#define PUT(x) printf("%d\n",x)
#define DPUT(x) printf("%.15lf\n",x)
#define GET(x,y) std::get<x>(y)
#define CHMAX(x,y) x = std::max(x,y)
#define CHMIN(x,y) x = std::min(x,y)
#define SP_END (i != n - 1 ? ' ' : '\n') ;

using namespace std;

using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = std::vector<ll>;
using vpll = std::vector<pll>;
using vpii = std::vector<pii>;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvpii = std::vector<vpii>;
using vch = std::vector<char>;
using vvch = std::vector<vch>;
using tiii = std::tuple<int, int, int>;

const ll mod197 = 1000000007LL;
const ll INF = 10000000000LL;

const double PI11 = 3.14159265359;

const int dis[5] = { 0,1,0,-1,0 };

const int disD[4] = { 0,1,1,0 };
const int disLD[3] = { 0,1,0 };

const char disC[4] = { 'U','D','R','L' };
const char disY[4] = { -1,1,0,0 };
const char disX[4] = { 0,0,1,-1 };

//最大公約数
ll gcd(ll a, ll b) {
	if (a%b == 0)
		return b;
	return gcd(b, a%b);
}

ll n, m;
ll x[100000], y[100000];


int main(void)
{
	cin >> n >> m;

	FOR(i, n)
		cin >> x[i];

	FOR(i, m)
		cin >> y[i];

	ll width = 0;
	FOR(i, n - 1) {
		width += (x[i + 1] - x[i]) * (n - i - 1) * (i + 1);
		width %= mod197;
	}

	ll height = 0;
	FOR(i, m - 1) {
		height += (y[i + 1] - y[i]) * (m - i - 1) * (i + 1);
		height %= mod197;
	}

	//cerr << width << " " << height << endl;

	cout << (width * height) % mod197 << endl;

	return 0;
}
