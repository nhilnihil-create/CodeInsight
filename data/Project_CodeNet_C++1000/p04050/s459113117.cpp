#include <iostream>
#include <vector>
#include <algorithm>
//#include <random>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
//#include <unordered_map>

using namespace std;

template<typename T> void uin(T &a, T b) {if (b < a) a = b;}
template<typename T> void uax(T &a, T b) {if (b > a) a = b;}

#define int long long
#define double long double
#define all(v) v.begin(), v.end()


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	vector<int> odd;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
		if (a[i] & 1) {
			odd.emplace_back(a[i]);
		}
	}
	if ((int)odd.size() > 2) {
		cout << "Impossible\n";
		return 0;
	}
	vector<int> v;
	if (!odd.empty()) v.emplace_back(odd[0]);
	for (int i = 0; i < m; ++i) {
		if (a[i] % 2 == 0) v.emplace_back(a[i]);
	}
	if ((int)odd.size() > 1) {
		v.emplace_back(odd[1]);
	}
	for (int i : v) cout << i << ' ';
	cout << '\n';
	vector<int> ans;
	if (v[0] != 1) ans.emplace_back(v[0] - 1);
	for (int i = 1; i < (int)v.size() - 1; ++i) ans.emplace_back(v[i]);
	if (v.size() != 1) {
		ans.emplace_back(v.back() + 1);
	}
	int sum = 0;
	for (int x : ans) sum += x;
	if (ans.size() == 1 && sum < n) ans.emplace_back(1);
	else if (ans.empty()) ans.emplace_back(1);
	cout << ans.size() << '\n';
	for (int i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
    return 0;
}

/*


*/
