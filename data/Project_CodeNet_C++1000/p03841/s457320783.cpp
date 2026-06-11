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
#include <time.h>
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
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
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
double eps = 1e-12;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll x[N];
    plglg p[N];
    REP(i, 0, N) {
        cin >> x[i];
        p[i] = plglg(x[i] - 1, i + 1);
    }
    sort(p, p + N);
    ll rem[3][N];
    REP(i, 0, N) {
        rem[0][i] = p[i].second;
        rem[1][i] = p[i].second - 1;
        rem[2][i] = N - p[i].second;
    }
    ll ans[N * N];
    queue<ll> que;
    ll pre = -1;
    bool ok = true;
    ll mark = 0;
    ll markb = 0;
    ll now = 0;
    // REP(i, 0, N) {
    //     cout << rem[0][i] << " " << rem[1][i] << endl;
    // }
    REP(i, 0, N) {
        ll nowrem = p[i].first - pre - 1;
        if (mark <= i) {
            if (nowrem < rem[1][i]) {
                ok = false;
                break;
            }
        }
        while (nowrem > 0) {
            if (mark < N) {
                while (rem[1][mark] == 0) {
                    mark++;
                }
            }
            if (mark < N) {
                // cout << now << " " << mark << " " << rem[1][mark] << " aaa" << endl;
                ans[now] = rem[0][mark];
                rem[1][mark]--;
                now++;
                nowrem--;
            } else {
                while (rem[2][markb] == 0) {
                    markb++;
                }
                // cout << now << " " << markb << " " << rem[2][markb] << " bbb" << endl;
                if (markb >= i) {
                    ok = false;
                    break;
                }
                ans[now] = rem[0][markb];
                rem[2][markb]--;
                now++;
                nowrem--;
            }
        }
        ans[p[i].first] = p[i].second;
        now = p[i].first + 1;
        pre = p[i].first;
    }
    if (!ok) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        REP(i, now, N * N) {
            while (rem[2][markb] == 0) {
                markb++;
            }
            ans[i] = rem[0][markb];
            rem[2][markb]--;
        }
        REP(i, 0, N * N) {
            cout << ans[i];
            if (i < N * N - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
