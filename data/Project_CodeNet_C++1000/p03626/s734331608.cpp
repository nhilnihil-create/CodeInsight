#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;
    ll mod = 1e9 + 7;
    ll ans = 1;
    string s1, s2;
    cin >> s1 >> s2;

    int i = 0;
    bool flag = 0;

    if (s1[0] == s2[0])
    {
        ans = 3;
        i++;
        flag = 0;
    }
    else
    {
        ans = 6;
        i += 2;
        flag = 1;
    }

    while (i < n)
    {
        if (flag)
        {
            if (s1[i] == s2[i])
            {
                i++;
                flag = 0;
            }
            else
            {
                i += 2;
                ans = (ans * 3) % mod;
            }
        }
        else
        {
            if (s1[i] == s2[i])
                i++;
            else
            {
                i += 2;
                flag = 1;
            }
            ans = (ans * 2) % mod;
        }
    }
    OP(ans % mod);
    return 0;
}