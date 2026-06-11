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

const int N = 1e5 + 5;
int a[N];
int n, s;
unordered_set<int> seen;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int cur = 1;
    while (1) {
        if (cur == 2) {
            cout << s << endl;
            exit(0);
        }
        if (seen.count(cur)) {
            cout << -1 << endl;
            exit(0);
        }
        seen.insert(cur);
        cur = a[cur];
        ++s;
    }
    return 0;
}
