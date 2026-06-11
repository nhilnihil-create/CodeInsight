#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll t = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = n; i--;) {
        a[i] += t;
        t += (b[i] - a[i] % b[i]) % b[i];
    }
    cout << t << endl;
}
