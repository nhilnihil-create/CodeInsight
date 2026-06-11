#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    ll N;
    cin >> N;

    ll fmin = LINF;
    for (int i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            ll x = i;
            ll y = N / i;
            ll dx = 0;
            while (x > 0) {
                dx++;
                x /= 10;
            }
            ll dy = 0;
            while (y > 0) {
                dy++;
                y /= 10;
            }

            fmin = min(fmin, max(dx, dy));
        }
    }
    cout << fmin << endl;
}