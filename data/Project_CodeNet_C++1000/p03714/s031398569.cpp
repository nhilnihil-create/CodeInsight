// 優先度付きキュー

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int a[N * 3];

    long before[N + 1];
    long after[N + 1];

    long sum = 0;
    long ans;

    // minpq = <1,2,3,4,9>
    // maxpq = <9,4,3,2,1>
    priority_queue<int, std::vector<int>, std::greater<int>> minpq;
    priority_queue<int> maxpq;

    for (int i = 0; i < 3 * N; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < N; i++)
    {
        sum += a[i];
        minpq.push(a[i]);
    }

    before[0] = sum;

    for (int k = 1; k <= N; k++)
    {
        int addnum = a[N - 1 + k];
        minpq.push(addnum);

        int removenum = minpq.top();
        minpq.pop();

        sum += addnum;
        sum -= removenum;

        before[k] = sum;
    }

    sum = 0;
    for (int i = 2 * N; i < 3 * N; i++)
    {
        sum += a[i];
        maxpq.push(a[i]);
    }

    after[0] = sum;

    for (int k = 1; k <= N; k++)
    {
        int addnum = a[2 * N - k];
        maxpq.push(addnum);

        int removenum = maxpq.top();
        maxpq.pop();

        sum += addnum;
        sum -= removenum;
        after[k] = sum;
    }

    ans = before[0] - after[N];
    for (int i = 0; i <= N; i++)
    {
        long tmp;
        tmp = before[i] - after[N - i];
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}