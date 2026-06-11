#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int digit(ll x)
{
    int d = 0;
    while (x) {
        x /= 10;
        ++d;
    }

    return d;
}

int f(ll a, ll b)
{
    return max(digit(a), digit(b));
}

int main()
{
    ll N;
    cin >> N;

    int ans = 100;
    for (ll i = 1; i*i <= N; ++i) {
        if (N % i == 0) {
            ll j = N / i;

            ans = min(ans, f(i, j));
        }
    }

    cout << ans << endl;

    return 0;
}