#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int h, w;
int dp[26];
int main()
{
    cin >> h >> w;
    rep(i, h)
    {
        string s;
        cin >> s;
        rep(j, w)
        {
            dp[s[j] - 'a']++;
        }
    }
    int cnt = 0;
    int odd = 0;
    rep(i, 26)
    {
        cnt += dp[i] % 4;
        odd += dp[i] % 2;
    }
    if (h % 2 && w % 2)
    {
        cnt -= (h + w - 1);
        odd--;
    }
    else if (h % 2)
    {
        cnt -= w;
    }
    else if (w % 2)
    {
        cnt -= h;
    }
    if (odd == 0 && cnt < 0 && (-cnt) % 4 == 0)
    {
        cout << "Yes" << endl;
    }
    else if (cnt + odd)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}