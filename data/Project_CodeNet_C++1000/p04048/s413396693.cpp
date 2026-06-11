#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
typedef long long ll;

ll get(ll n, ll m) {
    if (n == m) return n;
    if (n > m) swap(n, m);
    // m-n*z <= n
    // m <= n * (z+1)
    // m / n <= z+1
    ll z = (m + n - 1) / n - 1;
    return 2LL * z * n + get(n, m - z * n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    cout << n + get(n - x, x);
    return 0;
}
