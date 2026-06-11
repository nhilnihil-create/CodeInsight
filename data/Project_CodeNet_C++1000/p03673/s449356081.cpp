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

const int N = 2e5 + 5;
int n;
int a[N];
int b[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    int k = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (k) {
            b[l++] = a[i];
        } else {
            b[r--] = a[i];
        }
        k = 1 - k;
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}
