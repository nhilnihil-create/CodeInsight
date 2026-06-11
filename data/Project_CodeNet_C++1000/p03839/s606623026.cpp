#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> a(N+1);
    for (int i = 1; i <= N; i++) scanf("%lld", &a[i]);
    
    vector<ll> lsum(N+2, 0), rsum(N+2, 0);
    for (int i = 1; i <= N; i++) {
        lsum[i] = lsum[i-1] + max((ll)0, a[i]);
    }
    for (int i = N; i >= 1; i--) {
        rsum[i] = rsum[i+1] + max((ll)0, a[i]);
    }
    vector<ll> sum(N+2, 0);
    for (int i = 1; i <= K; i++) sum[K] += a[i];
    for (int i = K+1; i <= N; i++) sum[i] = sum[i-1] + a[i] - a[i-K];
    
    ll ans = 0;
    for (int i = K; i <= N; i++) {
        ans = max(ans, lsum[i-K]+rsum[i+1]);
        ans = max(ans, lsum[i-K]+rsum[i+1]+sum[i]);
    }
    cout << ans << endl;
}