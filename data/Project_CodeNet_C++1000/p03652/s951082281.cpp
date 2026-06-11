#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));
    for (vector<int> &row : A)
    {
        for (int &a : row)
        {
            cin >> a;
            a--;
        }
    }

    int ans = N;
    vector<bool> hold(M, true);
    for (int i = 0; i < M; i++)
    {
        vector<int> count(M, 0);
        int tmp = 0;
        int next = N;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                int sport = A[j][k];
                if (hold[sport])
                {
                    count[sport]++;
                    break;
                }
            }
        }
        for (int j = 0; j < M; j++)
        {
            if (tmp < count[j])
            {
                tmp = count[j];
                next = j;
            }
        }
        ans = min(ans, tmp);
        hold[next] = false;
    }
    cout << ans << endl;
}
