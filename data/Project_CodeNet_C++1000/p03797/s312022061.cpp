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

    ll s, c, ans;
    cin >> s >> c;

    if (2 * s < c)
    {
        ans = s;
        ll tmp = c - 2 * s;
        ans += tmp / 4;
    }
    else
        ans = c / 2;

    cout << ans << '\n';

    return 0;
}