#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)
#define pow10(n) int(1e##n + n)

typedef long long LL;
typedef pair<int, int> P;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;

bool isok(string &s)
{
    int bit = 0;
    for (auto c : s)
    {
        int flg = 1 << (c - '0');
        bit = bit | flg;
    }
    return __builtin_popcount(bit) == 1;
}

void solve()
{
    string S;
    cin >> S;
    map<char, int> mp;
    for (auto c : S)
    {
        mp[c]++;
    }

    int ans = INTINF;

    for (auto p : mp)
    {
        string T = S;
        int ops = 0;
        char c = p.first;
        while (!isok(T))
        {
            string R;
            for (int i = 0; i < T.length() - 1; i++)
            {
                if (T[i] == c)
                {
                    R.push_back(T[i]);
                }
                else if (T[i + 1] == c)
                {
                    R.push_back(T[i + 1]);
                }
                else
                {
                    R.push_back(T[i]);
                }
            }
            ops++;
            T = R;
        }
        ans = min(ans, ops);
    }

    std::cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
