# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <tuple>
# include <unordered_map>
# include <numeric>
# include <complex>
# include <bitset>
# include <random>
# include <chrono>
# include <cstdlib>
# include <tuple>
# include <array>
# include <climits>
#define ll long long
#define rep(i,rept) for (ll i = 0; i < rept; i++)
#define yes(b) std::cout<< (b ? "Yes" : "No")
#define YES(b) std::cout<< (b ? "YES" : "NO")
const ll INF = 1LL << 50;
using namespace std;
/*int ketawa(ll num) {
int dig, sum = 0;
while (num) {
dig = num % 10;
sum = sum + dig;
num = num / 10;
}
return sum;
}

bool keta(ll num, vector<int> v) {
int dig;
while (num) {
dig = num % 10;
for (auto& i : v) {
if (dig == i) {
return false;
}
}
num = num / 10;
}
return true;
}

ll func(ll a, ll b, ll c, ll d, int n) {
return ((c / (d - b) + n)*(d - b)) + (a % (d - b));
}
*/
int main(void) {
	int n = 50;
	ll k, a[50], m;
	cin >> k;
	m = k / n;
	rep(i, n) {
		a[i] = i + m;
	}
	k %= n;
	rep(i, k) {
		rep(j, n) {
			if (j != i) {
				a[j]--;
			}
		}
		a[i] += n;
	}
	cout << n << endl;
	rep(i, n) {
		cout << a[i];
		if (i < n - 1) {
			cout << " ";
		}
	}
	return 0;
}