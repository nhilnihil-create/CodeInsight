#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
using vll = vector<long long>;

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, a, b;
    cin >> n >> a >> b;

    vll x(n);
    rep(i, n) cin >> x[i];

    vll c(n,0);

    for (int i = 1; i < n; i++) {
        c[i] = a * (x[i] - x[i - 1]);

        if(c[i]>b){
            c[i] = b;
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += c[i];
    }
    cout << sum << endl;
}