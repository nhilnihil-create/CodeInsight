#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    vector<int> memo(H * W);
    vector<int> acc_a(N + 1);
    for (int i = 0; i < N; i++)
    {
        acc_a[i + 1] = acc_a[i] + a[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = acc_a[i]; j < acc_a[i + 1]; j++)
        {
            memo[j] = i;
        }
    }

    vector<vector<int>> ans(H, vector<int>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int jj = j;
            if (1 == i % 2)
            {
                jj = W - 1 - j;
            }
            ans[i][jj] = memo[W * i + j];
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << ans[i][j] +1<< ' ';
        }
        cout << endl;
    }

    return 0;
}