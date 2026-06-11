#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-11;

int main() {
    ll n;
    cin >> n;
    int a[105];
    fill(a, a + 105, 0);
    int minnum = 200;
    int maxnum = 0;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        a[b]++;
        minnum = min(minnum, b);
        maxnum = max(maxnum, b);
    }
    bool ok = true;
    if (a[minnum] != 1 && a[minnum] != 2) {
        ok = false;
    }
    if (a[minnum] == 1) {
        if (maxnum != 2 * minnum) {
            ok = false;
        } else {
            for (int i = minnum + 1; i <= maxnum; i++) {
                if (a[i] < 2) {
                    ok = false;
                }
            }
        }
    } else if (a[minnum] == 2) {
        if (maxnum != 2 * minnum - 1) {
            ok = false;
        } else {
            for (int i = minnum + 1; i <= maxnum; i++) {
                if (a[i] < 2) {
                    ok = false;
                }
            }
        }
    }
    if (ok) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
