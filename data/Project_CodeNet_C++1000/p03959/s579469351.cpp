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



int main() {
	int n;
	cin >> n;
	vector<int> t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> p(n);
	p[0] = 1;
	
	for (int i = 1; i < n; i++) {
		if (t[i] == t[i - 1]) {
			p[i] =t[i];
		}
		else {
			p[i] = 1;
			
		}

		
	}

	
	p[n - 1] = 1;
	
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] == a[i + 1]) {
			p[i] = min(p[i], a[i]);
		}
		else {
			p[i] = 1;
			
		}
	}

	int m = 0;
	for (int i = 0; i < n; i++) {
		m = max(m, t[i]);
	}

	bool isConsist = false;
	for (int i = 0; i < n; i++) {
		if (t[i] == m && a[i] == m) {
			isConsist = true;
		}
	}
	
	if (!isConsist) {
		cout << 0 << endl;
		return 0;
	}

	ll ans = 1;
	for (int i = 0; i < n; i++) {
		ans = (ans * p[i]) % MOD;
		//cout << p[i] << " ";
	}
	//cout << endl;

	cout << ans << endl;
}