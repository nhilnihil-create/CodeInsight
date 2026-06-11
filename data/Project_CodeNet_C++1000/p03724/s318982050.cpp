#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n, m;
    cin >> n >> m;
    int a[m], b[m], cnt[n] = {};
    rep (i, m) {
        cin >> a[i] >> b[i];
        cnt[a[i] - 1]++;
        cnt[b[i] - 1]++;
    }
    rep (i, n) {
        if (cnt[i] % 2 != 0) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}