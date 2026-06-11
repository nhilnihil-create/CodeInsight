#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<P> p(M);
    rep(i, M) cin >> p[i].first >> p[i].second;
    vector<vector<int>> city(N, vector<int>(N, 0));
    rep(i, M)
    {
        int y = p[i].first;
        int x = p[i].second;
        city[y - 1][x - 1]++;
        city[x - 1][y - 1]++;
    }
    rep(i, N)
    {
        int ans = 0;
        rep(j, N)
        {
            ans += city[i][j];
        }
        cout << ans << endl;
    }
    return 0;
}