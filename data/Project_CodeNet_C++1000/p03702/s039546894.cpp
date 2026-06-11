#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, A, B;
ll h[100000];
bool f(int k) {
    ll e = 0;
    for (int i = 0; i < N; i++) {
        ll x = h[i];
        x -= B*k;
        if (x > 0) {
            ll r = x / (A-B);
            if (x - r * (A-B) > 0) {
                r++;
            }
            e += r;
            if (e > k) return 0;
        }
    }
    return 1;
}
int main () {
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    long long low = 0, high = 1000000000;
    while (high - low > 1) {
        long long mid = (high + low) / 2;
        if (f(mid)) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    cout << high << endl;
}