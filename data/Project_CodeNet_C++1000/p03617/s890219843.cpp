#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rem(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int q, h, s, d;
    int n;
    cin >> q >> h >> s >> d >> n;
    ll dmin = min(min(q * 8, h * 4), min(s * 2, d));
    //cout << dmin << "\n";

    if (n % 2 == 0)
    {
        cout << dmin * n / 2 << "\n";
    }
    else
    {
        int m = n / 2;
        ll smin = min(min(q * 4, h * 2), s);
        cout << dmin * m + smin << "\n";
    }

    return 0;
}