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

constexpr int N = 105;
int a[N];
int n, sum;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    if (sum % 10) {
        cout << sum << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            if (a[i] % 10) {
                cout << sum - a[i] << endl;
                exit(0);
            }
        }
        cout << 0 << endl;
    }
    return 0;
}
