#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	int n;
	
	cin >> n;
	vector<int> a(3*n);
	long long int ans = 0;
	for (int i = 0; i <3* n; i++) {
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		ans += a.at(3*n - 2 - (2 * i));
	}
	cout << ans << endl;
	return 0;
}