#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1

using namespace std;

const int INF = 1e18;
void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("./sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, N;
    cin >> H >> W >> N;
    int a[N];
    rep(i, N) cin >> a[i];

    int masu[H][W];

    vector<int> color;
    rep(i, N)
    {
        rep(j, a[i])
        {
            color.push_back(i + 1);
        }
    }

    int count = 0;
    for (int h = 0; h < H; h++)
    {
        if (h % 2 == 0)
        {
            for (int w = 0; w < W; w++)
            {
                masu[h][w] = color[count];
                count++;
            }
        }
        else
        {
            for (int w = W - 1; 0 <= w; w--)
            {
                masu[h][w] = color[count];
                count++;
            }
        }
    }

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            cout << masu[h][w];
            if (w == w - 1)
                continue;
            cout << " ";
        }
        cout << endl;
    }
}

signed main()
{
    solve();
    return 0;
}
