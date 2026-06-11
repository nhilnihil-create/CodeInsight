#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

int main() {
    ll A, B, C;
    cin >> A >> B >> C;

    // if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
    //     cout << 0 << endl;
    //     return 0;
    // }

    for (int i = 0; i <= 10000000; i++) {
        if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
            cout << i << endl;
            return 0;
        }

        ll prev_A = A, prev_B = B, prev_C = C;
        A = prev_B / 2 + prev_C / 2;
        B = prev_A / 2 + prev_C / 2;
        C = prev_A / 2 + prev_B / 2;
    }
    cout << -1 << endl;
}