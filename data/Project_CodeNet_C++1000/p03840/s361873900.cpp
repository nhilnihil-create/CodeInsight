#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <set>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstring>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<double, double >pd;
typedef pair<string, string> sP;
typedef pair<ll, pair<ll, ll>> PP;


const ll mod = 1e4;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const double eps = 1e-10;
const double PI = 3.14159265358979323846;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };

#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second


int main() {
	ll I, O, T, J, L, S, Z, ans = 0;
	cin >> I >> O >> T >> J >> L >> S >> Z;
	if (min({ J, L,I }) >= 1) {
		ans += 6;
		I -= 1, L -= 1, J -= 1;
		ans += (I / 2) * 4;
		ans += O * 2;
		ans+= (J / 2) * 4;
		ans += (L / 2) * 4;
		I++, L++, J++;
	}
	ll ret = 0;
	ret += (I / 2) * 4;
	ret += O * 2;
	ret += (J / 2) * 4;
	ret += (L / 2) * 4;
	cout << max(ans / 2, ret / 2) << endl;
	return 0;
}

