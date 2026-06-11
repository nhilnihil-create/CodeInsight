#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    ll ans = 0;
    REP(i, N-1) {
        ans += A[i] / 2;
        if (A[i] % 2 == 1 && A[i+1] > 0) {
            A[i+1]--;
            ans++;
        }
    }
    ans += A.back() / 2;
    cout << ans << endl;
}