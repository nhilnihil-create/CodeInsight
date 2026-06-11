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
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    sort(ALL(A));
    vector<ll> cum(N);
    cum[0] = A[0];
    for (int i = 1; i < N; i++) cum[i] = A[i] + cum[i-1];
    int ans = 1;
    for (int i = N - 2; i >= 0; i--) {
        if (cum[i] * 2 < A[i+1]) break;
        ans++;
    }
    cout << ans << endl;
}