#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll a[200009], sum = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll res = 500000000000000LL;
    ll ps = a[0];
    for(int i=1; i<n; i++) {
        res = min(res, abs(sum - 2 * ps));
        ps += a[i];
    }
    cout << res << endl;
}