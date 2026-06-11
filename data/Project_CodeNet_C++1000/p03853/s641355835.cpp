#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int h, w;
    cin >> h >> w;
    char C[h][w];
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> C[i][j];
        }
    }

    rep(i, h)
    {
        rep(j, w)
        {
            cout << C[i][j];
        }
        cout << endl;
        rep(j, w)
        {
            cout << C[i][j];
        }
        cout << endl;
    }

    return 0;
}
