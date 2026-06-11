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
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	ll ans = 0;
	
	
	for (int i = 0; i < n - 1; i++) {
		ans += a[i] / 2;
		


		if (a[i]%2 == 1 && a[i + 1] != 0) {
			a[i + 1]--;
			ans++;
		}


	}

	ans += a[n - 1] / 2;

	
	cout << ans << endl;
}