#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, x;
    cin >> a >> b >> x;
    long long ans;
    
    if (a > 0)
    {
        ans = b/x - (a-1)/x;
    }
    else if (a == 0 && b > 0)
    {
        ans = b/x + 1;
    }
    else
    {
        ans = 1;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}