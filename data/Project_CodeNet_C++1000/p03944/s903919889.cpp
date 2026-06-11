#include <bits/stdc++.h>
using namespace std;

//セルで考えてみる。
int W, H, N;
int x[110], y[110], a[110];
int field[110][110];

int main()
{
    cin >> W >> H >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> a[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (a[i] == 1)
        {
            for (int j = 0; j < x[i]; j++)
            {
                for (int k = 0; k < H; k++)
                {
                    field[j][k] = 1;
                }
            }
        }
        else if (a[i] == 2)
        {
            for (int j = x[i]; j < W; j++)
            {
                for (int k = 0; k < H; k++)
                {
                    field[j][k] = 1;
                }
            }
        }
        else if (a[i] == 3)
        {
            for (int j = 0; j < W; j++)
            {
                for (int k = 0; k < y[i]; k++)
                {
                    field[j][k] = 1;
                }
            }
        }
        else
        {
            for (int j = 0; j < W; j++)
            {
                for (int k = y[i]; k < H; k++)
                {
                    field[j][k] = 1;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if(field[i][j] == 0) cnt++;
        }
    }
    cout << cnt << endl;    

    return 0;
}
