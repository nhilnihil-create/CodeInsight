#include <bits/stdc++.h>

int main()
{
    int n;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> forward;
    std::priority_queue<long long> back;
    long long sum[2]{};

    scanf("%d", &n);
    long long *mid_table = new long long[n];
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        scanf("%lld", &tmp);
        sum[0] += tmp;
        forward.push(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", mid_table + i);
    }
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        scanf("%lld", &tmp);
        sum[1] += tmp;
        back.push(tmp);
    }
    long long *sum_forward = new long long[n + 1], *sum_back = new long long[n + 1];
    sum_forward[0] = sum[0];
    for (int i = 0; i < n; i++)
    {
        forward.push(mid_table[i]);
        sum_forward[i + 1] = sum_forward[i] + mid_table[i] - forward.top();
        forward.pop();
    }
    sum_back[n] = sum[1];
    for (int i = n - 1; i >= 0; i--)
    {
        back.push(mid_table[i]);
        sum_back[i] = sum_back[i + 1] + mid_table[i] - back.top();
        back.pop();
    }
    long long max{-100000000000000};
    for (int i = 0; i < n + 1; i++)
    {
        max = std::max(max, sum_forward[i] - sum_back[i]);
    }
    printf("%lld\n", max);
    
    delete[] mid_table;
    delete[] sum_forward;
    delete[] sum_back;
    return 0;
}