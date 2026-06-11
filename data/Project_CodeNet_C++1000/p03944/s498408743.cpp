#include <bits/stdc++.h>
using namespace std;
int W, H, N;

void Fill(vector<vector<bool>> &size, int x, int y, int a)
{
    if (a == 1)
    {
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < x; j++)
            {
                size[i][j] = true;
            }
        }
    }
    else if (a == 2)
    {
        for (int i = 0; i < H; i++)
        {
            for (int j = x; j < W; j++)
            {
                size[i][j] = true;
            }
        }
    }
    else if (a == 3)
    {
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < W; j++)
            {
                size[i][j] = true;
            }
        }
    }
    else if (a == 4)
    {
        for (int i = y; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                size[i][j] = true;
            }
        }
    }
}

int main()
{
    cin >> W >> H >> N;

    vector<int> X(N);
    vector<int> Y(N);
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
        cin >> Y[i];
        cin >> A[i];
    }

    vector<vector<bool>> S(H, vector<bool>(W));
    for (int i = 0; i < N; i++)
    {
        Fill(S, X[i], Y[i], A[i]);
    }

    int res = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (!S[i][j])
                res++;
        }
    }
    cout << res << endl;
}