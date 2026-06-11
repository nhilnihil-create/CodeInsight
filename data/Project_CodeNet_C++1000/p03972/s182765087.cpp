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
    ll W, H;
    cin >> W >> H;
    ll p[W], q[H];
    for (int i = 0; i < W; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < H; i++) {
        cin >> q[i];
    }
    sort(p, p + W);
    sort(q, q + H);
    ll psum[W + 1], qsum[H + 1];
    psum[0] = 0;
    qsum[0] = 0;
    for (int i = 0; i < W; i++) {
        psum[i + 1] = psum[i] + p[i];
    }
    for (int i = 0; i < H; i++) {
        qsum[i + 1] = qsum[i] + q[i];
    }
    ll ans = psum[W] + qsum[H];
    for (int i = 0; i < H; i++) {
        int id = lower_bound(p, p + W, q[i]) - p;
        ans += psum[id] + q[i] * (W - id);
    }
    cout << ans << endl;
}
