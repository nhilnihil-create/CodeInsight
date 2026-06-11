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

const ll MAX = 1e9 + 5;

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}

	for (int i = 0; i < n; i++) {
		cout << 1 + i * (n + 1) << " ";
	}
	cout << endl;

	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = 1 + i * (n + 1);
	}
	reverse(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		b[p[i]] += i;
	}

	for (int bi : b) {
		cout << bi << " ";
	}

}