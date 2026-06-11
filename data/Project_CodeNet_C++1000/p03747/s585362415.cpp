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
    ll N, L, T;
    cin >> N >> L >> T;
    ll X[N];
    ll W[N];
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> W[i];
    }
    ll w = W[0];
    ll num = 0;
    for (int i = 1; i < N; i++) {
        if (w == 1 && W[i] == 2) {
            ll dif = X[i] - X[0];
            if (2 * T >= dif) {
                num += (2 * T - dif) / L + 1;
            }
        } else if (w == 2 && W[i] == 1) {
            ll dif = L - (X[i] - X[0]);
            if (2 * T >= dif) {
                num -= (2 * T - dif) / L + 1;
            }
        }
    }
    ll XX[N];
    for (int i = 0; i < N; i++) {
        if (W[i] == 1) {
            XX[i] = (X[i] + T) % L;
        } else {
            XX[i] = ((X[i] - T) % L + L) % L;
        }
    }
    sort(XX, XX + N);
    // for (int i = 0; i < N; i++) {
    //     cout << XX[i] << endl;
    // }
    ll ans[N];
    num = (num % N + N) % N;
    if (w == 1) {
        ll id = (ll)(upper_bound(XX, XX + N, (X[0] + T) % L) - XX) - 1;
        id = (id % N + N) % N;
        //cout << id << endl;
        for (int i = 0; i < N; i++) {
            ans[num] = XX[id];
            num = (num + 1) % N;
            id = (id + 1) % N;
        }
    } else {
        ll id = (ll)(lower_bound(XX, XX + N, ((X[0] - T) % L + L) % L) - XX);
        //id = (id % N + N) % N;
        for (int i = 0; i < N; i++) {
            ans[num] = XX[id];
            num = (num + 1) % N;
            id = (id + 1) % N;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}
