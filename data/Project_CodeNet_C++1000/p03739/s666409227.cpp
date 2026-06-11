#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N;
vector<int> A;


void input() {
    cin >> N;
    A = vector<int>(N);
    rep(i, N) cin >> A[i];
}


ll solve(bool p) {
    ll s = 0;
    ll ret = 0;
    rep(i, N) {
        s += A[i];
        if (p) {
            if (s <= 0) {
                ret += 1 - s;
                s += 1 - s;
            }
        } else {
            if (s >= 0) {
                ret += s + 1;
                s -= s + 1;
            }
        }
        p = !p;
    }
    return ret;
}


int main() {
    input();
    ll ans = min(solve(true), solve(false));
    cout << ans << endl;
}
