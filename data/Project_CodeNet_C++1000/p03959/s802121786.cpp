#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());
#define PAU system("pause")

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 28);
const ll LINF = 1e18;
const double PI = acos(-1);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vll T(N), A(N);
	REP(i, N)cin >> T[i];
	REP(i, N)cin >> A[i];
	vll ans(N);
	int pre = -1;
	REP(i, N) {
		if (pre != T[i]) {
			if (T[i] > A[i]) {
				ans[i] = 0;
				pre = T[i];
				continue;
			}
			else {
				ans[i] = 1;
				pre = T[i];
				continue;
			}
		}
		ans[i] = T[i];
		pre = T[i];
	}
	pre = -1;
	REPR(i, N) {
		if (pre != A[i]) {
			if (A[i] > T[i]) {
				ans[i] = 0;
				pre = A[i];
				continue;
			}
			else {
				ans[i] = min(ans[i], 1ll);
				pre = A[i];
				continue;
			}
		}
		ans[i] = min(ans[i], A[i]);
		pre = A[i];
	}
	ll n = 1;
	REP(i, N) {
		n *= ans[i];
		n %= MOD;
	}
	cout << n << endl;
	return 0;
}
