#include <bits/stdc++.h>
using namespace std;


void solve () {
    long long n, m;
    cin >> n >> m;
    long long f = min (n, m/2);
    m -= f * 2;
    long long s = m/4;
    cout << f + s;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
