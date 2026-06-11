#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    int N;
    cin >> N;
    const int MOD = 1e9 + 7;
    int64_t total = 1;
    map<int, int64_t> divisor;
    for (int i = 1; i <= N; i++)
    {
        int num = i;
        for (int j = 2; j <= i; j++)
        {
            while (num % j == 0)
            {
                divisor[j]++;
                num /= j;
            }
        }
    }
    for (auto x : divisor)
    {
        total = (total % MOD) * (x.second + 1) % MOD;
    }
    cout << total % MOD << endl;
}