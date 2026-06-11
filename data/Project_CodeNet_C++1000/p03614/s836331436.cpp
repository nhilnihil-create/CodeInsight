#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    rep(i, n)
    {
        if (p[i] == i + 1)
        {
            if (p[i + 1] == i + 2)
            {
                ans++;
                i++;
            }
            else
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}