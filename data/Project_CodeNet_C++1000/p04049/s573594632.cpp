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
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

int n, k;
vector<int> G[2020];
vector<int> depth;
vector<bool> vis;

void search(int at, int dep) {
    vis[at] = 1;
    depth[dep]++;
    for (auto &i : G[at]) {
        if (!vis[i]) search(i, dep + 1);
    }
}

int val(int r) {
    for (int i = 0; i < n; i++) depth[i] = vis[i] = 0;
    search(r, 0);
    int res = 0;
    for (int i = k / 2 + 1; i < n; i++) res += depth[i];
    /*
    for (int i = 0; i < n; i++) {
        cerr << depth[i] << " ";
    }
    cerr << endl;*/
    return res;
}

int valodd(int p, int q) {
    for (int i = 0; i < n; i++) depth[i] = vis[i] = 0;
    vis[q] = 1;
    search(p, 0);
    vis[q] = 0;
    search(q, 0);
    int res = 0;
    for (int i = k / 2 + 1; i < n; i++) res += depth[i];
    /*
    for (int i = 0; i < n; i++) {
        cerr << depth[i] << " ";
    }
    cerr << endl;*/
    return res;
}

int main() {
    cin >> n >> k;
    vector<int> a(n - 1), b(n - 1);
    depth.resize(n);
    vis.resize(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        a[i]--;  b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    int ans = 1e9;
    if (k % 2 == 0) {
        for (int i = 0; i < n; i++) {
            ans = min(ans, val(i));
            //cout << i _ val(i) << endl;
        }
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, valodd(a[i], b[i]));
            //cout << i _ val(i) << endl;
        }
    }
    cout << ans << endl;
}
