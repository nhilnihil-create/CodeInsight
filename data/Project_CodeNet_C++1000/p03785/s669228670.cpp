#include <bits/stdc++.h>
using namespace std;

int N, C, K;
int T[1000010];

int main()
{
    cin >> N >> C >> K;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &T[i]);
    }

    sort(T, T + N);

    int cnt = 0;
    for (int i = 0; i < N;)
    {
        int j = 0;
        while (i + j < N && T[i+j] - T[i] <= K && j < C)
        {
            j++; 
        }
        i += j;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
