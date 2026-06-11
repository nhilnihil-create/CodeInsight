#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

//typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
const double EPS = 1e-7;
const double MAX = 1000 + 5;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int p = 2;
	ll cnt = a[0] - 1;
	a[0] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == p) {
			p++;
			continue;
		}
		ll c = a[i] / p;
		if (a[i] % p == 0) {
			c--;
			a[i] = p - 1;
		}

		cnt += c;


	}

	cout << cnt << endl;
	
}