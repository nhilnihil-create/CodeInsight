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
int n, m, a, b;
bool ok;
unordered_set<int> st;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        int t;
        if (a == 1 || a == n) { // put b
            t = b;
            if (st.count(t)) {
                ok = true;
            } else {
                st.insert(t);
            }
        } else if (b == 1 || b == n) { // put a
            t = a;
            if (st.count(t)) {
                ok = true;
            } else {
                st.insert(t);
            }
        }
    }
    if (ok)
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
