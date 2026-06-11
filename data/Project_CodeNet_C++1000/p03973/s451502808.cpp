#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = a[0] - 1;
    int val = 2;
    for(int i = 1; i < n; i++) {
        if(a[i] == val) {
            val++;
            continue;
        }
        ans += a[i] / val - (a[i] % val == 0);
    }
    cout << ans << endl;
}