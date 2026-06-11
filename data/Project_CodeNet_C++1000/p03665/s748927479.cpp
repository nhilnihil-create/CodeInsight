// https://atcoder.jp/contests/agc017/tasks/agc017_a
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int N, P;
    cin >> N >> P;
    vector<ll> A(N);
    int even = 0;
    REP(i, N)
    {
        cin >> A[i];
        if (A[i] % 2 == 0) ++even;
    }
    if (even == N)
    {
        if (0 == P)
        {
            ll ans = 1;
            REP(i, N)
            {
                ans *= 2;
            }
            printf("%lld\n", ans);
            return 0;
        }
        else
        {
            printf("0\n");
            return 0;
        }
    }

    ll ans = 1;
    for (int i = 1; i <= N - 1; ++i)
    {
        ans *= 2;
    }
    printf("%lld\n", ans);
    return 0;
}
