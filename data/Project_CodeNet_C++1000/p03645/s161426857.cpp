#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll n, m; cin >> n >> m;
    ll a, b;
    vector<int> from1(n + 1, 0);
    vector<int> toN(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (a == 1 || b == 1) {
            if (a > b) swap(a, b);
            from1[b] = 1;
            if (toN[b] == 1) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
        if (a == n || b == n) {
            if (a > b) swap(a, b);
            toN[a] = 1;
            if (from1[a] == 1) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}