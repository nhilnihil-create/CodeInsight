#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, x, l, r, n, m, ans = 0;
    cin >> a >> b >> x;
    if(a % x == 0)
        l = a;
    else {
        l = ((a/x)+1) * x;
    }
    if(b % x == 0)
        r = b;
    else {
        r = (b/x) * x;
    }
    //cout << l << " " << r << endl;
    if(l > r || r < l) {
        cout << ans;
        return 0;
    }
    n = l/x;
    m = r/x;
    ans = m - n + 1;
    cout << ans;
}
