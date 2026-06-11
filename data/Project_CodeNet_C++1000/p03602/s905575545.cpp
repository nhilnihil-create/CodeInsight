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

int V;
int a[310][310];

int main() {
    int N;
    cin >> N;
    V = N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    bool ok = true;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            bool ok2 = true;
            for (int k = 0; k < N; k++) {
                if (k != i && k != j) {
                    if (a[i][k] + a[k][j] < a[i][j]) {
                        ok = false;
                    } else if (a[i][k] + a[k][j] == a[i][j]) {
                        ok2 = false;
                    }
                }
            }
            if (ok2) {
                ans += a[i][j];
            }
        }
    }
    if (ok) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}
