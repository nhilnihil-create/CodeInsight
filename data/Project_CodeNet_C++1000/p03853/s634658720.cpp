#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<char>> list(H, vector<char>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> list[i][j];
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 0; j < W; j++)
            {
                cout << list[i][j];
            }
            cout << endl;
        }
    }
}