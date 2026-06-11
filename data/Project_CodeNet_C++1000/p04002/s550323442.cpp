#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

ll H, W, N, ans[11];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main()
{
    scanf("%d%d%d", &H, &W, &N);
    set<pair<int, int>> st, br;
    ans[0] = (H - 2) * (W - 2);
    for (int i = 0; i < N; i++)
    {
        int y, x;
        scanf("%d%d", &y, &x);
        br.insert({--y, --x}), st.insert({y, x});
        for (int i = 0; i < 8; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 1 || ny > H || nx < 1 || nx > W)
                continue;
            st.insert({ny, nx});
        }
    }
    for (auto &p : st)
    {
        ll y = p.first, x = p.second, cnt = 0;
        cnt += (br.find(p) != br.end());
        for (int i = 0; i < 8; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W)
            {
                cnt = -1;
                break;
            }
            cnt += (br.find({ny, nx}) != br.end());
        }
        if (cnt != -1)
            ans[cnt]++, ans[0]--;
    }
    for (int i = 0; i < 10; i++)
        cout << ans[i] << endl;
}