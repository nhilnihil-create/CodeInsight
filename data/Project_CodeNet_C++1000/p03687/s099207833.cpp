#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

#define int long long

const int MOD = 1e9 + 7;
const int N = 504002;

string s;

signed main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        int n = s.size() - i;
        for (char c = 'a'; c <= 'z'; c++)
        {
            vector<int> x(s.size() + 1);
            x[s.size()] = 1e9;
            for (int j = s.size() - 1; j >= 0; j--)
            {
                if (s[j] == c) x[j] = 0;
                else x[j] = x[j + 1] + 1;
            }
            int t = 1;
            for (int j = 0; j < n; j++)
            {
                if (x[j] > i)
                    t = 0;
            }
            if (t)
            {
                cout << i;
                return 0;
            }
        }
    }
}
