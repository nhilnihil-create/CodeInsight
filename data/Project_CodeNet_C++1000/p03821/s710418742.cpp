#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    
    ll A[N], B[N];
    rep(i, N) cin >> A[i] >> B[i];

    ll ans = 0;
    for (int i=N-1; i>=0; i--) {
        if ((A[i] + ans)%B[i] != 0) {
            ans += B[i] - (A[i] + ans) % B[i];
        }
    }

    cout << ans << endl;

    return 0;
}