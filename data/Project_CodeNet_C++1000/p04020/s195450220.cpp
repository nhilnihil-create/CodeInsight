#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    int N; cin >> N;

    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    ll ans = 0;
    rep(i, N - 1) {
        if (A[i] % 2 == 1 && A[i+1] > 0) {
            A[i] -= 1;
            A[i+1] -= 1;
            ans += 1;
        }
    }
    rep(i, N) {
        ans += A[i] / 2;
    }
    cout << ans << endl;
    return 0;
}