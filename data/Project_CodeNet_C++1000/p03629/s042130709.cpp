#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int nextOcc[MAXN + 1][26];
int dp[MAXN + 1];

int main()
{
    string a;
    cin >> a;
    int n = (int) a.length();
    fill(nextOcc[n], nextOcc[n] + 26, n);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (a[i] - 'a' == j)
                nextOcc[i][j] = i;
            else
                nextOcc[i][j] = nextOcc[i + 1][j];
        }
    }
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int last = -1;
        for (int j = 0; j < 26; j++)
        {
            last = max(last, nextOcc[i][j]);
        }
        if (last == n)
            dp[i] = 1;
        else
            dp[i] = 1 + dp[last + 1];
    }
    int len = dp[0];
    stringstream ss;
    int ptr = 0;
    while (len--)
    {
        int key = 0;
        while (dp[nextOcc[ptr][key] + 1] != len)
            key++;
        ss << (char) (key + 'a');
        ptr = nextOcc[ptr][key] + 1;
    }
    cout << ss.str() << endl;
    return 0;
}
