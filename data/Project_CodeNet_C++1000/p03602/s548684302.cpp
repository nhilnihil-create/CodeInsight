#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <limits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int64_t>> mat(n);
    for (auto &row : mat)
        row.resize(n, numeric_limits<int64_t>::max());

    int64_t ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    auto minmat = mat;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (minmat[i][j] > minmat[i][k] + minmat[k][j])
                {
                    minmat[i][j] = minmat[i][k] + minmat[k][j];
                }
            }

    if (mat != minmat)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            bool check = true;
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j)
                    continue;
                if (minmat[i][j] >= minmat[i][k] + minmat[k][j])
                    check = false;
            }
            if (check)
                ans += minmat[i][j];
        }

    ans /= 2;
    cout << ans << endl;

    return 0;
}