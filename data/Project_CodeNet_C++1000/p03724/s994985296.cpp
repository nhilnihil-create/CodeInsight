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
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const int MAX = 1e5+5;


double p;


int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<int> e(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		e[a]++;
		e[b]++;
	}

	for (int i = 0; i < n; i++) {
		if (e[i] % 2 != 0) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

}