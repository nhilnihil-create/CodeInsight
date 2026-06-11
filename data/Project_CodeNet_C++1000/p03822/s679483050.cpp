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
    ll N;
    cin >> N;
    int a[N], b[N];
    a[0] = -1;
    fill(b, b + N, 0);
    for (int i = 1; i < N; i++) {
        cin >> a[i];
        a[i]--;
        b[a[i]]++;
    }
    // for (int i = 0; i < N; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    tiii c[N]; //高さ、番号、空き枠
    priority_queue<pii, vector<pii>, greater<pii> > que;
    for (int i = 0; i < N; i++) {
        c[i] = tiii(b[i], i, b[i]);
        if (b[i] == 0) {
            que.push(pii(b[i], i));
        }
    }
    while (!que.empty()) {
        pii p = que.top();
        que.pop();
        if (p.second == 0) {
            break;
        }
        int to = a[p.second];
        tiii tot = c[to];
        // cout << p.first << " " << p.second << endl;
        // cout << get<0>(c[to]) << " " << get<1>(tot) << " " << get<2>(tot) << endl;
        if (get<2>(tot) + p.first > get<0>(tot)) {
            get<0>(c[to]) = get<2>(c[to]) + p.first;
        }
        get<2>(c[to])--;
        if (get<2>(c[to]) == 0) {
            que.push(pii(get<0>(c[to]), get<1>(c[to])));
        }
    }
    ll ans = get<0>(c[0]);
    cout << ans << endl;
}
