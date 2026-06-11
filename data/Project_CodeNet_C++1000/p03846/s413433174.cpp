#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pw(x) (1LL << (x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

ll bigmod(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    unordered_map<int, int> cnt;

    for (int &x : v)
    {
        cin >> x;
        ++cnt[x];
    }

    // if odd leng: only one person has '0' as diff
    // And, all diffs should be divisible by 2, even or odd
    if (n & 1) // odd
    {
        if (cnt[0] != 1)
        {
            cout << 0;
            return 0;
        }
        cnt.erase(0);
    }

    for (auto x : cnt)
    {
        // cout << x.first << "->" << x.second << "\n";
        if (x.second & 1)
        {
            cout << 0;
            return 0;
        }
    }

    cout << bigmod(2, n / 2, 1e9 + 7);

    return 0;
}