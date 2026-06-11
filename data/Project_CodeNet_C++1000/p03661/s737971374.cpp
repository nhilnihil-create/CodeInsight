#include <bits/stdc++.h>

using namespace std;

int arr[200010];
long long sum[200010];

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    for(i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + arr[i];

    long long r = 1e18;
    for(i = 1; i < n; i++)
        r = min(r, abs(sum[i] - (sum[n] - sum[i])));

    printf("%lld\n", r);
    return 0;
}