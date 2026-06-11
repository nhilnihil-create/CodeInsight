#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define repd(i, a, b) for (int i = a; i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, 0, n)
    {
        int t;
        cin >> t;
        mp[min(8, t / 400)]++;
    }
    int ans = 0;
    rep(i, 0, 8)
    {
        if (mp[i] > 0)
            ans++;
    }
    if (ans == 0 && mp[8] > 0)
    {
        ans++;
        mp[8]--;
    }
    cout << ans << " " << ans + mp[8] << endl;
}
