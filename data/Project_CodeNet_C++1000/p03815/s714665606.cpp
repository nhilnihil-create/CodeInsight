#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pw(x) (1LL << (x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, ans;
    cin >> x;

    ans = x / 11 * 2;
    x %= 11;

    if (x > 0 && x <= 6)
        ++ans;
    else if (x > 6 && x <= 10)
        ans += 2;

    cout << ans << '\n';

    return 0;
}