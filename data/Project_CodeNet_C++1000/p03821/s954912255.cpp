#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    ll A[N], B[N];
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    ll ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        A[i] += ans;
        if((A[i] % B[i]) == 0) continue;
        ans += B[i] * ((A[i] + B[i] - 1) / B[i]) - A[i];
    }
    cout << ans << "\n";
    return 0;
}
