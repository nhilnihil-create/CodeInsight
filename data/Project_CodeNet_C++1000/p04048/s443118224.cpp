#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll n, x;

// 辺の長さが a, b の平行四辺形を通る光の軌跡の長さ
ll len(ll a, ll b) {
    if(b == 0)  return -a;
    return len(b, a % b) + (a/b) * (2*b);
}

int main() {
    cin >> n >> x;
    ll ans = x + (n - x);
    ans += len(max(x, n-x), min(x, n-x));
    cout << ans << endl;
}