#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <complex>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef complex<ld> compd;
#define rep(i,n)	for(int i=0;i<n;i++)
#define srep(i,a,n)	for(int i=a;i<n;i++)
#define REP(i,n)	for(int i=0;i<=n;i++)
#define SREP(i,a,n)	for(int i=a;i<=n;i++)
#define rrep(i,n)	for(int i=n-1;i>=0;i--)
#define RREP(i,n)	for(int i=n;i>=0;i--)
#define all(a)	(a).begin(),(a).end()
#define mp(a,b)	make_pair(a,b)
#define mt	make_tuple
#define pb	push_back
#define fst	first
#define scn second
#define bicnt(x)	__buildin__popcount(x)
#define debug(x)	cout<<"debug: "<<x<<endl
#define DEBUG 0

const ll inf = (ll)1e8;
const ll mod = 998244353;
const ld eps = 1e-9;
const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };

ll dist[300][300];

int main() {
	int n;	cin >> n;
	rep(i, n)	rep(j, n)	cin >> dist[i][j];
	rep(i, n)	rep(j, n)	rep(k, n) {
		if (dist[i][j] > dist[i][k] + dist[k][j]) {
			cout << -1 << endl;
			return 0;
		}
	}
	ll ret = 0;
	rep(i, n)	rep(j, n)	ret += dist[i][j];
	ret /= 2;
	rep(i, n)	rep(j, i)	rep(k, n) {
		if (k == i || k == j)	continue;
		if (dist[i][j] == dist[i][k] + dist[k][j]) {
			ret -= dist[i][j];
			break;
		}
	}
	cout << ret << endl;
	return 0;
}