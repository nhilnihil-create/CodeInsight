#include <iostream>
#include <deque>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long arr[100005] = { 0 }, m = 0;

long long calc(size_t n)
{

    for(size_t i = 0; i < n; i++)
        cin >> arr[i];

    n = n - 1;

    for(size_t i = n; i >= 1; i--)
        arr[i] = arr[i] - arr[i - 1];

    long long sum = 0;
    for(size_t i = 1; i <= n; i++) {
        long long acc = arr[i];
        acc = (acc * i) % MOD;
        acc = (acc * (n - i + 1)) % MOD;
        sum = (sum + acc) % MOD;
    }

    return sum;
}

int main()
{
    size_t n = 0, m = 0;

    cin >> n >> m;

    printf("%lld", (calc(n) * calc(m)) % MOD);
}
