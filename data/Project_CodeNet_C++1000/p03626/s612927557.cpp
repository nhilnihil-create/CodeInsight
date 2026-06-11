#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    ll ans;
    int pos, i; //0が縦、1が横
    //先頭のみ例外処理
    if (s1[0] == s2[0])
    {
        i = 1;
        ans = 3;
        pos = 0;
    }
    else
    {
        i = 2;
        ans = 6;
        pos = 1;
    }

    while (i < s1.length())
    {
        if (pos == 0 && s1[i] == s2[i])
        {
            ans = (ans * 2) % MOD;
            i += 1;
            pos = 0;
        }
        else if (pos == 0 && s1[i] != s2[i])
        {
            ans = (ans * 2) % MOD;
            i += 2;
            pos = 1;
        }
        else if (pos == 1 && s1[i] == s2[i])
        {
            i += 1;
            pos = 0;
        }
        else if (pos == 1 && s1[i] != s2[i])
        {
            ans = (ans * 3) % MOD;
            i += 2;
            pos = 1;
        }
    }

    cout << ans << endl;
}