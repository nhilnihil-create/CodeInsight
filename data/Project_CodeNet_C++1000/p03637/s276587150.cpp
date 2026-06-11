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
int n, t, a, b, c;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t % 4 == 0) {
            ++a;
        } else if (t % 2 == 0) {
            ++b;
        } else {
            ++c;
        }
    }
    // bbbbcacac
    if (b) {
        if (a >= c) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (c <= a + 1)
            cout<< "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
