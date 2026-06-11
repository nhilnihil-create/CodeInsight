#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

#define endl '\n'
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int MAXN = 1e5 + 5;
ll fastPow(ll x, ll b)
{
    if (b == 0)
        return 1;
    else if (!(b & 1))
    {
        return fastPow(x * x, b / 2);
    }
    else
        return x * fastPow(x * x, (b - 1) / 2);
}
//__builtin_popcount ();
struct def
{
    string h = ">";
};
int main()
{
    FAST
        ll x;
        cin>>x;
        ll ans = 2 * (x / 11);
        if(x%11==0)
            return cout << ans, 0;
        if (x % 11 <= 6)
            cout << ans + 1 << endl;
            else 
            {
                cout << ans + 2 << endl;
            }

            return 0;
}