#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    string result = "No";
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (M * i + N * j - 2 * i * j == K)
            {
                result = "Yes";
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}