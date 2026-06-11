#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;

    ll hoge = pow(k-1, n-1);
    ll ans = k * hoge;

    cout << ans << endl;

    return 0;
}