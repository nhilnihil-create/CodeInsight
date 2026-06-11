#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


const int mod = 1e9 + 7;

pair<string, bool> bits(int x, int n, int k)
{
    int c = 0;
    bool r = false;
    string ret = "1";
    rep(i, n - 1)
    {
        if (x % 2)
        {
            ret += '1';
            c++;
        }
        else
        {
            ret += '0';
        }
        x /= 2;
    }
    if (c == k - 1)
        r = true;

    return make_pair(ret, r);
}

ll cost(int a[], int n, string s)
{
    ll res = 0;
    int height = 0;
    rep(i, n)
    {
        if (s[i] == '1')
        {
            if (height < a[i])
                height = a[i];
            else
            {
                res += height + 1 - a[i];
                height++;
            }
        }
        else
        {
            if (height < a[i])
            {
                height = a[i];
                res += a[i] - height;
            }
        }
    }
    return res;
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, n) cin >> a[i];
    ll ans = 10e12;
    pair<string, bool> res;

    rep(i, pow(2, n - 1))
    {
        res = bits(i, n, k);
        if (res.second)
            ans = min(cost(a, n, res.first), ans);
    }

    cout << ans << endl;

    return 0;
}
