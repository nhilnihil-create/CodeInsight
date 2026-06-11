#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e12;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1
#define MAX_N 100100 * 3

ll n, m;
int x[100100];
int y[100100];
ll cntx[100100];
ll cnty[100100];

int main() {
	cin >> n >> m;
	rep(i, n)cin >> x[i];
	rep(i, m)cin >> y[i];
	bool f = 1;
	ll cnt = n - 1;
	rep(i, (n - 1) / 2 + 1) {
		cntx[i] = cnt;
		cntx[n - 2 - i] = cnt;
		cnt += ((n - 1) - 2 * (i + 1));
		cnt %= MOD;
	}
	cnt = m - 1;
	rep(i, (m - 1) / 2 + 1) {
		cnty[i] = cnt;
		cnty[m - 2 - i] = cnt;
		cnt += ((m - 1) - 2 * (i + 1));
		cnt %= MOD;
	}

	ll ansx = 0, ansy = 0;
	rep(i, n - 1) {
		ansx += (x[i + 1] - x[i])*cntx[i] % MOD;
		ansx %= MOD;
	}
	rep(i, m - 1) {
		ansy += (y[i + 1] - y[i])*cnty[i] % MOD;
		ansy %= MOD;
	}
	cout << ansx*ansy%MOD << endl;
}