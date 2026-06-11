#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<P> s(n), cp(m);
    rep(i, n) cin >> s[i].first >> s[i].second;
    rep(i, m) cin >> cp[i].first >> cp[i].second;
    rep(i, n)
    {
        int d = 1e9, id = -1;
        rep(j, m)
        {
            int x = abs(s[i].first - cp[j].first);
            int y = abs(s[i].second - cp[j].second);
            if (x + y < d)
            {
                d = x + y;
                id = j + 1;
            }
        }
        cout << id << endl;
    }
}

int main()
{
    solve();
    return 0;
}