#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int W, H, N;
    cin >> W >> H >> N;

    vector<vector<int>> map(W, vector<int>(H, 0));

    int x, y, a;
    int k = 0;
    while (k < N)
    {
        cin >> x >> y >> a;
        if (a == 1)
        {
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < H; j++)
                {
                    map[i][j] = 1;
                }
            }
        }
        else if (a == 2)
        {
            for (int i = x; i < W; i++)
            {
                for (int j = 0; j < H; j++)
                {
                    map[i][j] = 1;
                }
            }
        }
        else if (a == 3)
        {
            for (int i = 0; i < W; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    map[i][j] = 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < W; i++)
            {
                for (int j = y; j < H; j++)
                {
                    map[i][j] = 1;
                }
            }
        }
        k++;
    }

    int ans = 0;
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (map[i][j] == 0)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}