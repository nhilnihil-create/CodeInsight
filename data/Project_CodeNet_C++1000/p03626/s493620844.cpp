#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1 << 30)
#define LLINF (1LL << 60)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ll ans = 1LL;
    if (s[0] == t[0])
    {
        (ans *= 3LL) %= MOD;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == t[i])
            {
                if (s[i - 1] == t[i - 1])
                {
                    (ans *= 2LL) %= MOD;
                }
            }
            else
            {
                if (s[i - 1] == t[i - 1])
                {
                    (ans *= 2LL) %= MOD;
                }
                else
                {
                    (ans *= 3LL) %= MOD;
                }
                i++;
            }
        }
    }
    else
    {
        (ans *= 6LL) %= MOD;
        for (int i = 2; i < n; i++)
        {
            if (s[i] == t[i])
            {
                if (s[i - 1] == t[i - 1])
                {
                    (ans *= 2LL) %= MOD;
                }
            }
            else
            {
                if (s[i - 1] == t[i - 1])
                {
                    (ans *= 2LL) %= MOD;
                }
                else
                {
                    (ans *= 3LL) %= MOD;
                }
                i++;
            }
        }
    }
    cout << ans << endl;
}