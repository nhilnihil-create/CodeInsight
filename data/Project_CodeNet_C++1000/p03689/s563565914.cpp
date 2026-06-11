#include <bits/stdc++.h>

using namespace std;

//#define _FILES
#define PB push_back
#define MP make_pair
#define X first
#define Y second

const int MAXN = 505;

int ans[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);

    #ifdef _FILES
        freopen("","r",stdin);
        freopen("","w",stdout);
    #endif // _FILES
    int h, hh, w, ww;
    cin >> h >> w >> hh >> ww;

    if (((h % hh) == 0) && ((w % ww) == 0))
    {
        cout << "No" << endl;
        return 0;
    }

    if (h % hh)
    {
        for (int j=1;j<=w;j++)
        {
            for (int i=1;i<=h;i++)
            {
                if (j % ww)
                {
                    ans[i][j] = 0;
                    continue;
                }

                if (i % hh)
                {
                    ans[i][j] = 100000;
                }
                else
                {
                    ans[i][j] = -((hh - 1) * 100000 + 1);
                }

            }
        }
    }
    else
    {
        for (int i=1;i<=h;i++)
        {
            for (int j=1;j<=w;j++)
            {
                if (i % hh)
                {
                    ans[i][j] = 0;
                    continue;
                }

                if (j % ww)
                {
                    ans[i][j] = 100000;
                }
                else
                {
                    ans[i][j] = -((ww - 1) * 100000 + 1);
                }
            }
        }
    }
    cout << "Yes" << endl;
    for (int i=1;i<=h;i++)
    {
        for (int j=1;j<=w;j++)
        {
            if (j > 1) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}

