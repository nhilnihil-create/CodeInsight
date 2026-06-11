#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    cin >> N;
    vector<long long> sum(N);
    for (int i = 0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        if (i == 0) sum[0] = tmp;
        else sum[i] = sum[i-1] + tmp;
    }
    long long res = -1;
    for (int i = 0; i < N-1; i++)
    {
        if (res < 0 || res > abs(sum[N - 1] - 2 * sum[i]))
            res = abs(sum[N - 1] - 2 * sum[i]);
    }
    cout << res << endl;
    return 0;
}