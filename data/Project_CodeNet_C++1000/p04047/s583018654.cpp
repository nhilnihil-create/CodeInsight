#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <complex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>

#define ft first
#define sc second
#define pb push_back
#define len(v) (int)v.size()
// #define int ll

using namespace std;
typedef long long ll;
typedef long double ld;


signed main() {
	#ifdef PC
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	int n;
	cin >> n;
	vector<int> a(2 * n, 0);
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < 2 * n; i += 2) {
		ans += a[i];
	}
	cout << ans << endl;
}