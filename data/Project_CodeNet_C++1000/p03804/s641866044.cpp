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
	int  n, m;
	cin >> n >> m;

	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];


	}

	vector<string> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];


	}


	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			bool canExist = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					canExist = canExist && (a[i + k][j + l] == b[k][l]);


				}
			}
			if (canExist) {
				cout << "Yes" << endl;
				return 0;
			}

		}
	}
	cout << "No" << endl;
}