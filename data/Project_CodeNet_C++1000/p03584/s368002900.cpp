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
    ll N, K;
    cin >> N >> K;
    ll A[N], B[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    bool bit[30];
    for (int i = 0; i < 30; i++) {
        if ((K & (1 << i)) > 0) {
            bit[i] = true;
        } else {
            bit[i] = false;
        }
    }
    ll sum[30];
    fill(sum, sum + 30, 0);
    for (int i = 29; i >= 0; i--) {
        if (bit[i] || i == 0) {
            for (int j = 0; j < N; j++) {
                bool ok = true;
                for (int k = 29; k > i; k--) {
                    if (!bit[k] && ((A[j] & (1 << k)) > 0)) {
                        ok = false;
                    }
                }
                if (i != 0) {
                    if ((A[j] & (1 << i)) > 0) {
                        ok = false;
                    }
                } else {
                    if (!bit[0] && (A[j] % 2 == 1)) {
                        ok = false;
                    }
                }
                if (ok) {
                    sum[i] += B[j];
                    //cout << i << " " << j << endl;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 30; i++) {
        ans = max(ans, sum[i]);
    }
    cout << ans << endl;
}
