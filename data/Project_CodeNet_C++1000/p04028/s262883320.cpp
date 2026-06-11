#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

const long long MOD = 1e9 + 7;

int kat[5001][2501];
ll dp[20][5001];
ll res[5001];
int adds[5001];
ll pref[5001][5001];
ll Get[5001];
int n, m;
string s;


/*
5
000

ans = 9
*/
long long get(int cnt)
{
    if (cnt < 0)
        return 0;
    return Get[cnt];
}

int main()
{
    kat[0][0] = 1;
    for (int i = 0; i < 5000; i++)
    {
        for (int j = 0; j <= 2500; j++)
        {
            if (j + 1 <= 2500)
            {
                kat[i + 1][j + 1] = kat[i][j];
                kat[i + 1][j + 1] %= MOD;
            }
            if (j - 1 >= 0)
            {
                kat[i + 1][j - 1] += kat[i][j];
                kat[i + 1][j - 1] %= MOD;
            }
        }
    }
    long long x = 2;
    adds[0] = 1;
    for (int i = 2; i <= 5000; i += 2)
    {
        adds[i] = ((ll)kat[i][0] * x) % MOD;
        //cout << kat[i][0] << " ";
        x *= 2;
        x %= MOD;
    }
    cin >> n >> s;
    m = s.size();
    for (int i = 0; i <= 5000; i++)
    {
        dp[0][i] = adds[i];
    }
    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i < 5000; i++)
        {
            for (int h1 = 0; h1 <= i; h1++)
            {
                int h2 = i - h1;
                dp[j][i] = (dp[j][i] + dp[j - 1][h1] * dp[j - 1][h2]) % MOD;
            }
        }
    }
    vector<int> pw;
    for (int i = 0; i < 20; i++)
    {
        pw.push_back(m % 2);
        m /= 2;
    }
    //reverse(pw.begin(), pw.end());
    m = s.size();
    Get[0] = 1;
    for (int j = 0; j < 20; j++)
    {
        if (pw[j] == 1)
        {
            for (int i = 5000; i > 0; i--)
            {
                for (int k = 1; k <= i; k++)
                {
                    Get[i] = (Get[i] + Get[i - k] * dp[j][k]) % MOD;
                }
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        ;//cout << Get[i] << " ";
    }
    //cout << endl;


    pref[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pref[i + 1][j + 1] = (pref[i + 1][j + 1] + 2 * pref[i][j]) % MOD;
            pref[i + 1][max(0, j - 1)] = (pref[i + 1][max(0, j - 1)] + pref[i][j]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        //cout << i << " " << pref[n - i][0] << " " << get(i - m) << endl;
        ans += pref[n - i][0] * get(i - m);
        ans %= MOD;
    }
    cout << ans % MOD;
}
