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
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll okini = 1;
    ll okival = 0;
    int innum[m + 1];
    int outnum[m + 1];
    fill(innum, innum + m + 1, 0);
    fill(outnum, outnum + m + 1, 0);
    ll ans = 0;
    ll defa[m + 1];
    fill(defa, defa + m + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        innum[a[i]]++;
        outnum[a[i + 1]]++;
        if (okini <= a[i + 1] && (a[i] < okini || a[i + 1] < a[i])) {
            okival++;
            ans += a[i + 1] - okini + 1;
        } else {
            if (a[i] < a[i + 1]) {
                // if (okini == a[i]) {
                //     okival++;
                // }
                ans += a[i + 1] - a[i];
            } else {
                ans += m + 1 - a[i] + a[i + 1] - 1;
            }
        }
        if (a[i] < a[i + 1]) {
            defa[a[i + 1]] += a[i + 1] - a[i];
        } else {
            defa[a[i + 1]] += m + 1 - a[i] + a[i + 1] - 1;
        }
    }
    ll tmp = ans;
    //cout << tmp << " " << okival << endl;
    for (int i = 2; i <= m; i++) {
        tmp -= okival;
        tmp += defa[i - 1];
        okival += innum[i - 1];
        okival -= outnum[i - 1];
        if (tmp < ans) {
            ans = tmp;
        }
        //cout << tmp << " " << okival << endl;
    }
    cout << ans << endl;
}
