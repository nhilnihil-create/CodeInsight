#include <iostream>
#include <algorithm>

using namespace std;

int64_t dp[101][101][301];
int64_t w[100];
int64_t v[100];

int main()
{
    int N;
    int64_t W;

    cin >> N >> W;
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }

    int64_t w0 = w[0];
    for (int i = 0; i < N; i++)
    {
        w[i] -= w0;
    }

    for (int i = 0; i <= N; i++)
    {
        for (int k = 0; k <= N; k++)
        {
            for (int64_t weight = 0; weight <= 300; weight++)
            {
                if (i == 0 || k == 0)
                {
                    dp[i][k][weight] = k == 0 ? 0 : -1;
                    continue;
                }
                int64_t cand = -1;

                if (dp[i - 1][k][weight] >= 0)
                {
                    cand = max(cand, dp[i - 1][k][weight]);
                }
                if (weight - w[i - 1] >= 0 && dp[i - 1][k - 1][weight - w[i - 1]] >= 0)
                {
                    cand = max(cand, dp[i - 1][k - 1][weight - w[i - 1]] + v[i - 1]);
                }

                dp[i][k][weight] = cand;
            }
        }
    }

    int64_t result = 0;
    for (int k = 0; k <= N; k++)
    {
        for (int64_t weight = 0; weight <= 300; weight++)
        {
            if (W >= w0 * k + weight)
            {
                result = max(result, dp[N][k][weight]);
            }
        }
    }

    cout << result << endl;
    return 0;
}