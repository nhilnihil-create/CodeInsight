#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

const int P = 1e9 + 7;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) 
		cin >> x[i];
	
	int m = 0;
	vector<int> p;
	vector<int> used(n);
	ll ans = 1;
	for (int i = 0; i < n; ++i) {
		++m;
		if (m > (x[i] + 1) / 2) {
			ans *= m;
			ans %= P;
			--m;
			used[i] = 1;
			p.push_back(i);
		}
	}

	for (int i = 1; i <= m; ++i) {
		ans *= i;
		ans %= P;
	}

	cout << ans << endl;
}