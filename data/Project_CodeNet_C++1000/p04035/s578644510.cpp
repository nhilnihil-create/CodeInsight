#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, L;
    cin >> N >> L;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }

    bool judge = 0;
    int l, r;
    rep(i, N - 1) {
        if (A[i + 1] + A[i] >= L) {
            judge = 1;
            l = i;
            r = i + 1;
            break;
        }
    }

    if (!judge) {
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;
    for (int i = 1; i <= l; i++) {
        cout << i << endl;
    }
    for (int i = N - 1; i > r; i--) {
        cout << i << endl;
    }
    cout << r << endl;
    return 0;
}