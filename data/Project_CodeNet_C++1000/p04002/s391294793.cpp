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

int dx[] = {-1, 0, 1}, dy[] = {-1, 0, 1};

int h, w;
bool in(int y, int x) { return 0 < y && y < h - 1 && 0 < x && x < w - 1; }

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> h >> w >> n;
    set<P> st;
    map<P, int> cnt;
    vector<int> num(10, 0);
    num[0] = (h - 2) * (w - 2);
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        rep(j, 3) rep(k, 3)
        {
            int y = a + dy[j], x = b + dx[k];
            if (!in(y, x))
                continue;
            int now = cnt[P(y, x)];
            num[now]--;
            cnt[P(y, x)]++;
            num[now + 1]++;
        }
    }
    rep(i, 10) cout << num[i] << endl;
}