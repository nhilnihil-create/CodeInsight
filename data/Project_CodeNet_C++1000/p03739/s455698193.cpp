#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, ans;
    cin >> n;
    vector<ll>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sum = 0;
    ll sumb = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i % 2 == 0) {
            if (sum < 1) {
                sumb += 1-sum;
                sum = 1;
            }
        } else {
            if (sum > -1) {
                sumb += sum+1;
                sum = -1;
            }
        }
    }
    ans = sumb;
    sum = 0;
    sumb = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i % 2 == 1) {
            if (sum < 1) {
                sumb += 1-sum;
                sum = 1;
            }
        } else {
            if (sum > -1) {
                sumb += sum+1;
                sum = -1;
            }
        }
    }
    cout << min(ans, sumb) << endl;
}
