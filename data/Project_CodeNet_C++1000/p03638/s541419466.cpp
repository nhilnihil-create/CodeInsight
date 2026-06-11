#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    vector<pair<int, int>> color(N);
    rep(i, N)
    {
        int a;
        cin >> a;
        color[i] = make_pair(a, i + 1);
    }
    sort(color.rbegin(), color.rend());
    vector<int> ans;
    rep(i, N)
    {
        rep(j, color[i].first)
        {
            ans.push_back(color[i].second);
        }
    }

    rep(i, H)
    {
        rep(j, W)
        {
            if (i % 2 == 0)
                cout << ans[i * W + j] << " ";
            else
                cout << ans[i * W + W - 1 - j] << " ";
        }
        cout << endl;
    }

    return 0;
}