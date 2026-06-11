#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <functional>
#include <numeric>
#include <chrono>
using ll = long long;
using namespace std;

const ll MOD = 1e9 + 7;
#define REP(i, n) for (int(i) = 0; (i) < (n); ++(i))
// bool operator<(const pair<int, int> &a, const pair<int, int> &b)
// {
//     if (a.first == b.first)
//         return a.second < b.second;
//     return a.first < b.first;
// };

/*unsigned int xor128(void)
{
    static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned int t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
unsigned int xor128rnd(unsigned int m)
{
    return xor128() % m;
}*/
vector<vector<string>> v(27);

vector<pair<int, int>> vp;
int main(void)
{
    int N;
    cin >> N;
    vector<int> ans;
    int maxn = 1;
    while (maxn * (maxn + 1) / 2 < N)
        maxn++;
    for (int i = 1; i <= maxn; ++i)
    {
        if (i != (maxn + 1) * maxn / 2 - N)
            printf("%d\n", i);
    }
    return 0;
}