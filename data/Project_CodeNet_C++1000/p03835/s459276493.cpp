#include <bits/stdc++.h>
#define reps(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define rep(i, n) reps(i, 0, n - 1)
#define sper(i, s, n) for (int i = (s); i >= (int)(n); i--)
#define per(i, n) sper(i, n - 1, 0)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int k, s;
    cin >> k >> s;
    int ans = 0;
    reps(x, 0, k) reps(y, 0, k)
    {
        int z = s - x - y;
        if (z < 0 || z > k)
            continue;
        ans++;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}