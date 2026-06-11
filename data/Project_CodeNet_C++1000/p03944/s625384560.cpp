#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int W, H, N;
    cin >> W >> H >> N;
    vector<vector<int>> rect(H, vector<int>(W, 1));
    for (int i = 0; i < N; i++)
    {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1)
        {
            for (int j = 0; j < H; j++)
            {
                for (int k = 0; k < x; k++)
                {
                    rect[j][k] = 0;
                }
            }
        }
        else if (a == 2)
        {
            for (int j = 0; j < H; j++)
            {
                for (int k = x; k < W; k++)
                {
                    rect[j][k] = 0;
                }
            }
        }
        else if (a == 3)
        {
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k < W; k++)
                {
                    rect[j][k] = 0;
                }
            }
        }
        else if (a == 4)
        {
            for (int j = y; j < H; j++)
            {
                for (int k = 0; k < W; k++)
                {
                    rect[j][k] = 0;
                }
            }
        }
    }
    int area = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (rect[i][j] == 1)
            {
                area++;
                //cout << i << ", " << j << endl;
            }
        }
    }
    cout << area << endl;
    return 0;
}