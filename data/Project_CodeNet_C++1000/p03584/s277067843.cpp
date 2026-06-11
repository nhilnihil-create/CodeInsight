#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
ll A[100000];
ll B[100000];
int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    ll mask = 0;
    ll ans = 0;
    for (int i = 29; i >= 0; i--) {
        if ((K & (1 << i)) == 0) {
            mask |= (1 << i);
            continue;
        }
        ll sum = 0;
        for (int j = 0; j < N; j++) {
            if (A[j] & mask) continue;
            if (A[j] & (1 << i)) continue;
            sum += B[j];
        }
        ans = max(ans, sum);
    }
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] & mask) continue;
        sum += B[i];
    }
    ans = max(ans, sum);
    cout << ans << endl;
}