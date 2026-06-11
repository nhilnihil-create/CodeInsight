#include <bits/stdc++.h>

#define N_MAX 200002

using namespace std;

int n;

string s;

int dp[N_MAX][26];
int mic[N_MAX];

int step[N_MAX][26];

int main()
{
    cin >> s;
    n = s.size();
    for(int j = 0; j < 26; j++)
        dp[n][j] = 1;
    mic[n] = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        mic[i] = -1;
        for(int j = 0; j < 26; j++)
        {
            if(s[i] - 'a' == j)
            {
                dp[i][j] = dp[i + 1][mic[i + 1]] + 1;
                step[i][j] = mic[i + 1];
            }
            else
            {
                dp[i][j] = dp[i + 1][j];
                step[i][j] = j;
            }
            if(mic[i] == -1 || dp[i][j] < dp[i][mic[i]])
                mic[i] = j;
        }
    }
    for(int i = 0, j = mic[0]; i <= n; i++)
    {
        if(i == n || s[i] - 'a' == j)
            cout << char(j + 'a');
        j = step[i][j];
    }
    cout << "\n";
    return 0;
}
