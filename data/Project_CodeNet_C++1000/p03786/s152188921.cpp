#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll>A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), greater<ll>());
    vector<ll>sum(N+1);
    sum[0] = 0;
    for (int i = 0; i < N; i++) {
        sum[i+1] = sum[i] + A[N-i-1];
    }

    vector<bool>check(N, false);
    check[N-1] = true;
    ll ans = 1;
    for (int i = 1; i < N; i++) {
        ll s = sum[N-i];
        if (2*s >= A[i-1] && check[N-i]) {
            ans++;
            check[N-i-1] = true;
        } else {
            break;
        }
    }
    cout << ans << endl;
}
