#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
//const int mod = 998244353;

int cnt[100010];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    rep(i, n)
    {
        int a;
        cin >> a;
        a--;
        cnt[a]++;
    }
    rep(i, 100010) if (cnt[i] > 2)
    {
        if (cnt[i] % 2 == 0)
            cnt[i] = 2;
        else
            cnt[i] = 1;
    }
    int tmp = 0;
    rep(i, 100010)
    {
        if (cnt[i] > 1)
        {
            cnt[i]--;
            if (tmp == 0)
                tmp = 1;
            else
                tmp = 0;
        }
    }
    int ans = 0;
    rep(i, 100010) ans += cnt[i];
    cout << ans - tmp << endl;
}