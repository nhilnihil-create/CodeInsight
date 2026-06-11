#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool re = false;

    ll ans = pow(10, 18);

    ll count = 0;

    ll sum = 0;

    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(re) {
            if(sum <= 0) {
                count -= sum - 1LL;
                sum = 1LL;
            }
        } else {
            if(sum >= 0) {
                count += sum + 1LL;
                sum = -1LL;
            }
        }
        re = !re;
    }

    ans = min(ans, count);

    re = true;

    count = 0;

    sum = 0;

    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(re) {
            if(sum <= 0) {
                count -= sum - 1LL;
                sum = 1LL;
            }
        } else {
            if(sum >= 0) {
                count += sum + 1LL;
                sum = -1LL;
            }
        }
        re = !re;
    }

    ans = min(ans, count);

    cout << ans << endl;
}