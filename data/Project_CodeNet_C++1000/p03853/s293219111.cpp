#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
typedef long long ll;
int main()
{
    int h, w;
    cin >> h >> w;
    char C[h + 10][w + 10];
    rep(i, 0, h)
    {
        rep(j, 0, w) cin >> C[i][j];
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << C[i][j];
        }
        cout << endl;
        for (int j = 0; j < w; j++)
        {
            cout << C[i][j];
        }
        cout<<endl;
    }

}