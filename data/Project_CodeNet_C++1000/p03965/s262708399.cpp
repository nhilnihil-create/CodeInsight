#include <iostream>
#include <string>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    pair<int, int> p[n + 1];
    p[0] = make_pair(0, 0);
    p[1] = make_pair(1, 0);
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <=n; ++i)
    {
        if (s[i - 1] == 'g')
        {
            if (p[i-1].first > p[i-1].second)
            {
                dp[i] = dp[i - 1] + 1;
                p[i] = p[i - 1];
                p[i].second++;
            }
            else
            {
                dp[i] = dp[i - 1];
                p[i] = p[i - 1];
                p[i].first++;
            }
        }
        else
        {
            if(p[i-1].first > p[i-1].second )
            {
                dp[i] = dp[i - 1];
                p[i] = p[i - 1];
                p[i].second++;
            }
            else 
            {
                dp[i] = dp[i-1]-1;
                p[i] = p[i-1];
                p[i].first++;
            }
        }
    }
    cout << dp[n] << endl;
}

int main()
{
    solve();
    return 0;
}