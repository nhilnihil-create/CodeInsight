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
#include <tuple>
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
int x[100100];

const int max_n = 100100;
ll fact[max_n];
void calc_fact() {
    fact[0] = 1;
    for (ll i = 1; i < max_n; i++)
        fact[i] = (fact[i-1] * i) % mod;
}

ll solve() {
    calc_fact();
    ll res = 1;
    int r = 0;
    for (int i = 0; i < n; i++) {
        int t = 2 * r - 1;
        if (x[i] > t+1) {
            r++;
        } else if (x[i] == t+1) {
            res *= (r+1);
            res %= mod;
        }
    }
    res *= fact[r];
    res %= mod;
    return res;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
