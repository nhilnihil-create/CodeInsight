#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
lli calc(lli a, lli b)
{
    if (a % b == 0) {
        return a / b - 1;
    } else {
        return a / b;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<lli> a(n);
    rep(i, n) cin >> a[i];
    int state = 1;
    lli ans = 0;
    rep(i, n)
    {
        //cout << state << endl;
        if (i != 0) {
            if (state < a[i]) {
                ans += calc(a[i], state);
            } else if (state == a[i]) {
                state++;
            }
        } else {
            ans += calc(a[i], state);
            state++;
        }
    }
    cout << ans << endl;
}
