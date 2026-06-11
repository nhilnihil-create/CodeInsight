#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 51;
int n, m, k, ans;
string a[N], b[N];

bool check(int x, int y) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[x + i][y + j] != b[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i + m <= n; ++i) {
        for (int j = 0; j + m <= n; ++j) {
            if (check(i, j)) {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
