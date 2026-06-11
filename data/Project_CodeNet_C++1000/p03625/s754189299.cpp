#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll n; cin >> n;
    
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    
    ll length1 = -1;
    ll length2 = -1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1] && length1 == -1) {
            length1 = a[i];
            i++;
        }
        else if (a[i] == a[i + 1] && length1 != -1  && length2 == -1) {
            length2 = a[i];
            break;
        }
    }

    if (length1 == -1 || length2 == -1) cout << 0 << endl;
    else cout << length1 * length2 << endl;

    return 0;
}