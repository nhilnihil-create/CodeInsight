#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i < (int)(b); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll MOD = (ll)pow(10.0, 9.0) + 7;
pint dx[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

ll min(ll a, ll b)
{

	return (a < b) ? a : b;
}
ll max(ll a, ll b) { return (a > b) ? a : b; }




ll N;

vector <ll> P;
ll sum[2 * 100005];

int main() {
	cin >> N;

	P.resize(N);
	rep(i, N) {
		cin >> P[i];
		if (i != 0)
			sum[i] = sum[i - 1] + P[i];
		else
			sum[i] = P[i];
	}
	
	ll m = inf;

	rep(i, N-1) {

		m = min(abs( (sum[N-1] - sum[i]) - sum[i]), m);
	}

	cout << m << endl;

	return 0;
}