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

struct edge {
    int to, cost;
};

int V;
vector<edge> G[1000000];
ll d[1000000];
vector<int> rk[1000000];
ll cnt[1000000];

void addedge(int st, int ed, int co) {
    edge e;
    e.to = ed;
    e.cost = co;
    G[st].push_back(e);
}

void bfs() {
    fill(d, d + V, -1);
    queue<int> que;
    que.push(0);
    d[0] = 0;
    rk[0].push_back(0);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (int i = 0; i < (int)G[p].size(); i++) {
            edge e = G[p][i];
            if (d[e.to] == -1) {
                d[e.to] = d[p] + 1;
                rk[d[p] + 1].push_back(e.to);
                que.push(e.to);
            }
        }
    }
}

int main() {
    ll n;
    cin >> n;
    V = n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pii ab[n - 1];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        ab[i] = pii(a - 1, b - 1);
        addedge(a - 1, b - 1, 1);
        addedge(b - 1, a - 1, 1);
    }
    bfs();
    ll maxrk = 0;
    for (int i = 0; i < n; i++) {
        maxrk = max(maxrk, d[i]);
    }
    fill(cnt, cnt + n, -1);
    bool ok = true;
    for (int i = maxrk; i > 0; i--) {
        for (int j = 0; j < (int)rk[i].size(); j++) {
            int p = rk[i][j];
            //cout << p << endl;
            if (G[p].size() == 1) {
                cnt[p] = a[p];
                continue;
            }
            ll sum = 0;
            ll cntmax = 0;
            for (int k = 0; k < (int)G[p].size(); k++) {
                edge e = G[p][k];
                if (d[e.to] >= d[p]) {
                    sum += cnt[e.to];
                    cntmax = max(cntmax, cnt[e.to]);
                }
            }
            cnt[p] = 2 * a[p] - sum;
            if (cnt[p] < 0) {
                ok = false;
                //cout << "bbb" << endl;
                break;
            }
            //ll tmp = (sum - cnt[p]) / 2;
            ll tmp = a[p] - cnt[p];
            if (tmp < 0 || tmp > min(sum - cntmax, sum / 2)) {
                ok = false;
                //cout << "aaa" << endl;
                //cout << tmp << " " << sum - cntmax << " " << sum / 2 << endl;
                break;
            }
        }
        if (!ok) {
            break;
        }
    }
    ll zerosum = 0;
    ll zerocntmax = 0;
    for (int i = 0; i < (int)rk[1].size(); i++) {
        int p = rk[1][i];
        zerosum += cnt[p];
        zerocntmax = max(zerocntmax, cnt[p]);
    }
    if (ok) {
        if (G[0].size() != 1) {
            if (zerosum % 2 == 1 || zerosum / 2 != a[0] || zerosum / 2 > zerosum - zerocntmax) {
                ok = false;
            }
        } else {
            if (zerosum != a[0]) {
                ok = false;
            }
        }
    }
    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
