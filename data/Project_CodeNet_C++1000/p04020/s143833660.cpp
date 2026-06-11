#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    ll ans = 0;
    cin >> N;
    vector<ll>A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll pre = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            pre = 0;
            continue;
        }
        if (pre > 0) {
            ans += (A[i]+pre)/2;
            if ((A[i]+pre) % 2 == 0) {
                pre = 0;
            } else {
                pre = 1;
            }
        } else {
            ans += (A[i]/2);
            if (A[i] % 2 == 0) {
                pre = 0;
            } else {
                pre = 1;
            }
        }
    }
    cout << ans << endl;
}
