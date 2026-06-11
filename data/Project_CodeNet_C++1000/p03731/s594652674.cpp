#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N, T;
    cin >> N >> T;
    vi S(N);
    rep(i, N) {
        cin >> S[i];
    }

    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans += min(S[i + 1] - S[i], T);
    }
    ans += T;

    cout << ans << endl;
}