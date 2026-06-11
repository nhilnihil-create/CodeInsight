#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    ll ans = 0;
    ll t = 0;
    ll cand = 0;
    for (int i = 30; i >= 1; i--) {
        if (((K >> i) & 1) == 0) continue;
        t += (1 << i) - 1;
        cand = 0;
        for (int j = 0; j < N; j++) {
            if ((A[j] | t) == t) cand += B[j];
        }
        ans = max(ans, cand);
        t += 1;
    }
    cand = 0;
    for (int j = 0; j < N; j++) {
        if ((A[j] | K) == K) cand += B[j];
    }
    ans = max(ans, cand);
    cout << ans << endl;
    return 0;
}