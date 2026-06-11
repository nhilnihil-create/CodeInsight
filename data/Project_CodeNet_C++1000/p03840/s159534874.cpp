#include <algorithm>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod 1000000007
#define int long long
#define double long double
#define INF INT_MAX
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int a, b, c, d, e, f, g;
signed main() {
	cin >> a >> b >> c >> d >> e >> f >> g;
	if (a && d && e)cout << b + max(3 + (a - 1) / 2 * 2 + (d - 1) / 2 * 2 + (e - 1) / 2 * 2, a / 2 * 2 + d / 2 * 2 + e / 2 * 2) << endl;
	else cout << b + a / 2 * 2 + d / 2 * 2 + e / 2 * 2 << endl;
}