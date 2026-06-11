# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 1e17 - 10;
const double PI = acos(-1);
typedef pair<LL, LL> Pll;
typedef pair<LL, LL> Vec2;
LL h, w, n, m, s, t, ans[1000000], b[10000000], num = 1, sum = 0;
pair<LL, LL>a[10000000];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
		if (b[a[i].first] == 1) {
			cout << "No" << endl;
			return 0;
		}
		b[a[i].first] = 1;
		ans[a[i].first] = i;
	}
	using item = std::pair<LL, LL>;
	std::sort(a+1, a+n+1);
	sum = n*n;
	for (int i = n; i >= 1; i--) {
		int num = 0;
		if (a[i].second == n)continue;
		for (int j = sum; j >= 1; j--) {
			if (ans[j] >= 1) {}
			else if(j>a[i].first){
				ans[j] = a[i].second;
				num++;
			}
			if (num == n - a[i].second) {
				sum = j;
				break;
			}
			if(j==1){
				cout << "No" << endl;
				return 0;
			}

		}
	}
	
	t = 1; sum = 0;
	for (int i = 1; i <= n*n; i++) {
		if (a[t].second == 1) {
			t++;
			if (t == n + 1)break;
		}
		if (ans[i]>=1) {}
		else {
			ans[i] = a[t].second;
			sum++;
		}
		if (sum == a[t].second-1) {
			t++;
			sum = 0;
			if (t == n+1)break;
		}
		if (a[t].first <= i) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n*n; i++) {
		cout << ans[i];
		if (i != n*n)
			cout << " ";
	}
	cout << endl;
	return 0;
}