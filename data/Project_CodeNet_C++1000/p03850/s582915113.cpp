#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n;
ll a[100100];
char op[100100];
ll dp[100100][3];

ll solve() {
    dp[0][0] = a[0];
    dp[0][1] = dp[0][2] = -1e18;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 2; j++) {
            ll s = (op[i]=='+'?1:-1)*(j%2?-1:1)*a[i];
            dp[i][j] = dp[i-1][j] + s;
            if (j < 2) dp[i][j] = max(dp[i][j], dp[i-1][j+1] + s);
            if (j < 1) dp[i][j] = max(dp[i][j], dp[i-1][j+2] + s);
        }
        for (int j = 2; j > 0; j--) {
            if (op[i] == '-' && j > 0) {
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
    }
    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}

void input() {
    cin >> n;
    cin >> a[0];
    for (int i = 1; i < n; i++) cin >> op[i] >> a[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
