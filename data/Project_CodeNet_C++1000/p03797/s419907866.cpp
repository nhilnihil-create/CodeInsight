#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, ans;
    cin >> n >> m;
    ans = min(n, m/2);
    n -= ans;
    m -= ans*2;
    ans += m/4;
    cout << ans;
}