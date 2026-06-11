#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int x = 0;
    int ans = 0;
    rep(i, n)
    {
        if (s[i] == 'D')
        {
            x--;
        }
        else
        {
            x++;
        }
        ans = max(ans, x);
    }

    cout << ans << endl;
    return 0;
}
