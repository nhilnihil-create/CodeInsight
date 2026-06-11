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
#define _USE_MATH_DEFINES
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
ll inf = llmax / 2;

int main() {
    ll a[7];
    for (int i = 0; i < 7; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    ans += a[1];
    if (a[0] >= 1 && a[3] % 2 == 1 && a[4] % 2 == 1) {
        ans += 3;
        a[0]--;
        a[3]--;
        a[4]--;
    } else if (a[0] % 2 == 1 && a[3] >= 1 && a[4] % 2 == 1) {
        ans += 3;
        a[0]--;
        a[3]--;
        a[4]--;
    } else if (a[0] % 2 == 1 && a[3] % 2 == 1 && a[4] >= 1) {
        ans += 3;
        a[0]--;
        a[3]--;
        a[4]--;
    }
    ans += (a[3] / 2) * 2;
    ans += (a[4] / 2) * 2;
    ans += (a[0] / 2) * 2;
    cout << ans << endl;
}
