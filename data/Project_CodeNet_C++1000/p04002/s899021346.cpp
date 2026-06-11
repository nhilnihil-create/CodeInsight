#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll H, W, N, ans[11];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}, y, x, cnt;

int main()
{
    scanf("%d%d%d", &H, &W, &N);
    set<pair<int, int>> st, br;
    ans[0] = (H - 2) * (W - 2);
    for (int i = 0; i < N; i++)
    {
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
        y = p.first, x = p.second, cnt = 0;
        cnt += (br.find(p) != br.end());
        for (int i = 0; i < 8 && cnt != -1; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W)
                cnt = -1;
            cnt += (br.find({ny, nx}) != br.end());
        }
        if (cnt != -1)
            ans[cnt]++, ans[0]--;
    }
    for (int i = 0; i < 10; i++)
        printf("%lld\n", ans[i]);
}