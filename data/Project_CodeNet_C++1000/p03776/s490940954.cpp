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

int n, A, B;
ll a[51];
ll C[51][51];

void init() {
    C[0][0] = 1;
    for (int i = 1; i <= 50; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

int main() {
    init();
    cin >> n >> A >> B;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, greater<ll>());
    if (A > B)
        swap(A, B);
    double sum = 0;
    for (int i = 0; i < A; ++i) {
        sum += a[i];
    }
    double mean = sum / A;
    cout << mean << endl;
    int li = n - 1;
    int ri = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == a[A - 1]) {
            li = min(li, i);
            ri = max(ri, i);
        }
    }
    int left = A - li;
    int tt = ri - li + 1;
    if (li == 0) {
        ll ans = 0;
        for (int i = A; i <= min(tt, B); ++i) {
            ans += C[tt][i];
        }
        cout << ans << endl;
    } else {
        cout << C[tt][left] << endl;
    }

    return 0;
}
