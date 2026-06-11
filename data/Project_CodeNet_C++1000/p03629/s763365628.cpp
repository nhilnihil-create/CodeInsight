#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 27;

unordered_map<char, int> mn, prv;

int dp[N], p[N];
char ch[N];

int main()
{    
    string s;
    
    cin >> s;
    
    int n = s.size();
    
    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++)
    {
        prv[s[i]] = i;
        dp[i] = N;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (prv.count(c) == 0)
            {
                dp[i] = 1;
                ch[i] = c;
                p[i] = -1;
                break;
            }
            
            if (prv[c] > 0 && dp[i] > (dp[prv[c] - 1] + 1))
                dp[i] = dp[prv[c] - 1] + 1, ch[i] = c, p[i] = prv[c] - 1;
        }
    }
    
    vector<char> ans;
    
    int i = n - 1;
    
    while (i > -1)
    {
        ans.push_back(ch[i]);
        i = p[i];
    }
    
    for (char c : ans)
        cout << c;
    
    return 0;    
}
