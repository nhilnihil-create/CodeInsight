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
LL h, w, n, m, s, ans = 0, num = 1, sum = 0, a[100000];
string str,stt;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) {
			ans = a[i] - 1;
			a[i] = 1;
		}
		else {
			int f = 0;
			if(a[i] > num+1) {
				f = 1;
				ans += a[i] / (num + 1) - (a[i] % (num + 1) == 0 ? 1 : 0);
				a[i] = 1;
			}
		}
		num = max(num, a[i]);
	}
	
	cout << ans << endl;
	return 0;
}
