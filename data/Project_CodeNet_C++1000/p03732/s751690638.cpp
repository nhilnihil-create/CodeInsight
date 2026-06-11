#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, W;
    cin >> N >> W;

    long long w[N];
    long long v;
    vector<vector<long long>> v_list(4);
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v;
        v_list[w[i] - w[0]].push_back(v);
    }
    for (int i = 0; i < 4; i++)
    {
        sort(v_list[i].rbegin(), v_list[i].rend());
    }

    vector<vector<long long>> v_sum(4);
    for (int i = 0; i < 4; i++)
    {
        v_sum[i] = vector<long long>(v_list[i].size() + 1, 0);
        for (int j = 0; j < v_list[i].size(); j++)
        {
            v_sum[i][j + 1] = v_sum[i][j] + v_list[i][j];
        }
    }

    vector<long long> count(4);
    long long score;
    long long ans = 0;
    long long weight;
    for (int i = 0; i * w[0] <= W && i <= v_list[0].size(); i++)
    {
        for (int j = 0; i * w[0] + j * (w[0] + 1) <= W && j <= v_list[1].size(); j++)
        {
            for (int k = 0; i * w[0] + j * (w[0] + 1) + k * (w[0] + 2) <= W && k <= v_list[2].size(); k++)
            {
                for (int l = 0; i * w[0] + j * (w[0] + 1) + k * (w[0] + 2) + l * (w[0] + 3) <= W && l <= v_list[3].size(); l++)
                {
                    count[0] = i;
                    count[1] = j;
                    count[2] = k;
                    count[3] = l;
                    score = 0;
                    for (int m = 0; m < 4; m++)
                    {
                        score += v_sum[m][count[m]];
                    }
                    ans = max(ans, score);
                }
            }
        }
    }
    cout << ans << endl;
}
