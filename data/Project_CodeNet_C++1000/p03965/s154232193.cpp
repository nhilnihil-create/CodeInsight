#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    rep(i, s.length())
    {
        if (i % 2 == 0)
        {
            if (s[i] == 'p')
                ans--;
        }
        else
        {
            if (s[i] == 'g')
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}