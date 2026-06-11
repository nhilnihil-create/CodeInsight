#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

int main() {
    int n, m, mx = 1e5 + 1;
    cin >> n >> m;
    vector<int> x(mx, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x[a]++;
    }

    int is[m] = {}, pr[m] = {};
    for (int i = 0; i < mx; i++) {
        pr[i % m] += 2 * (x[i] / 2);
        is[i % m] += x[i] % 2;
    }
    for (int i = 0; i < m; i++) cerr << pr[i] _ is[i] << endl;

    int ans = 0;
    for (int i = 1; 2 * i < m; i++) {
        int k = min(is[i], is[m - i]);
        ans += k;
        is[i] -= k;  is[m - i] -= k;
    }
    ans += (is[0] + pr[0]) / 2;
    if (m % 2 == 0) {
        ans += (is[m / 2] + pr[m / 2]) / 2;
    }

    for (int i = 1; 2 * i < m; i++) {
        if (is[i] == 0) {
            int k = is[m - i];
            ans += min(k, pr[i]);
            pr[i] -= min(k, pr[i]);
            ans += (pr[i] + pr[m - i]) / 2;
        }
        else {
            int k = is[i];
            ans += min(k, pr[m - i]);
            pr[m - i] -= min(k, pr[m - i]);
            ans += (pr[i] + pr[m - i]) / 2;
        }
    }
    cout << ans << endl;

}
