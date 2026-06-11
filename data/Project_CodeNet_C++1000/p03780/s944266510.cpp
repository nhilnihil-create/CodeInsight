#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

ll a[5000];
bool dp[5001][5000];

int main()
{
    ll N, K;

    cin >> N >> K;
    for (int i = 0; i < N;i++)
    {
        cin >> a[i];
    }

    sort(a, a + N);

    int l, r, m;

    l = 0;
    r = N - 1;

/*
    for (int i = 0; i < N;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
*/
    while (true)
    {
        for (int i = 0; i < 5000; i++)
        {
            for (int j = 0; j < 5000; j++)
            {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;

        m = (r + l) / 2;

        //cout << "l = " << l << " m = " << m  << " r = " << r << endl;

        for (int x = 1; x <= N; x++)
        {
            for (int y = 0; y < K; y++)
            {
                if (x == m + 1 || y - a[x - 1] < 0)
                {
                    dp[x][y] = dp[x - 1][y];
                }
                else
                {
                    dp[x][y] = (dp[x - 1][y - a[x - 1]] || dp[x - 1][y]);
                }
            }
        }

        bool t = false;

        for (int y = K - a[m]; y < K; y++)
        {
            if (y < 0 || dp[N][y] == true)
            {
                //cout << "y = " << y << endl;
                t = true;
                break;
            }
        }

        if (l >= r)
        {
            if (t == true)
            {
                cout << m << endl;
            }
            else
            {
                cout << m + 1 << endl;
            }
            break;
        }

        if (t == true)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return 0;
}