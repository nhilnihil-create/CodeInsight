#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

ll H, W, N;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
ll ans[11];

int main()
{
    cin >> H >> W >> N;
    set<pair<int, int>> st, br;
    ans[0] = (H - 2) * (W - 2);
    for (int i = 0; i < N; i++)
    {
        int y, x;
        cin >> y >> x;
        y--, x--;
        pair<int, int> p = make_pair(y, x);
        br.insert(p);
        st.insert(p);
        for (int i = 0; i < 8; i++)
        {
            ll ny = y + dy[i], nx = x + dx[i];
            if (ny < 1 || ny > H)
                continue;
            if (nx < 1 || nx > W)
                continue;
            pair<ll, ll> q = make_pair(ny, nx);
            st.insert(q);
        }
    }
    for (auto &p : st)
    {
        ll y = p.first, x = p.second, cnt = 0;
        if (br.find(p) != br.end())
            cnt++;
        for (int i = 0; i < 8; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W)
            {
                cnt = -1;
                break;
            }
            pair<int, int> q = make_pair(ny, nx);
            if (br.find(q) != br.end())
                cnt++;
        }
        if (cnt != -1)
            ans[cnt]++, ans[0]--;
    }
    for (int i = 0; i < 10; i++)
        cout << ans[i] << endl;
}