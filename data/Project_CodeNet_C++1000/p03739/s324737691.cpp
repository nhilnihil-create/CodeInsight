#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    ll ans = 10000000000000000;
    ll sum = 0;
    cin >> n;
    vector<ll>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i % 2 == 0) {
            if (sum >= 0) {
                cnt += sum + 1;
                sum = -1;
            }
        } else {
            if (sum <= 0) {
                cnt += 1 - sum;
                sum = 1;
            }
        }
    }

    ans = min(ans, cnt);

    sum = 0;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i % 2 == 0) {
            if (sum <= 0) {
                cnt += 1 - sum;
                sum = 1;
            }
        } else {
            if (sum >= 0) {
                cnt += sum + 1;
                sum = -1;
            }
        }
    }
    ans = min(ans, cnt);
    cout << ans << endl;
}
