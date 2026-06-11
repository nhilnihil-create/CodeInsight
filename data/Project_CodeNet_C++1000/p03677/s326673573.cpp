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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
#define ALL(x)    (x).begin(),(x).end()
#define UNIQ(c)   (c).erase(unique(ALL((c))), end((c)))
#define mp        make_pair
#define eb        emplace_back
#define REP(i, a) for (int i = 0; i < (a); i++)

int n, m;
int a[101010];
LL imos[101010];
LL ans;
LL add[101010];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
		if (i) {
			ans += min((a[i] + m - a[i - 1]) % m, 1 + a[i] % m);
			add[a[i] + 1] += (a[i] + m - a[i - 1]) % m;
			imos[a[i - 1] + 1]++;
			imos[a[i] + 1]--;
			if (a[i] < a[i - 1])imos[0]++;
		}
	}
	for (int i = 1; i < 101010; i++) {
		imos[i] += imos[i - 1];
	}
	LL minl = ans;
	for (int i = 1; i < m; i++) {
		ans -= imos[i - 1];
		ans += add[i];
		minl = min(minl, ans);
	}
	cout << minl << endl;
}