#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N; cin >> N;
    vector<int> ts(N), as(N);
    for (auto &ti : ts) cin >> ti;
    for (auto &ai : as) cin >> ai;
    // 各山の高さhiについて取りうる値の範囲を計算していく
    vector<pair<int, int>> tHiRanges(N), aHiRanges(N);
    int maxHi = 0;
    for (int i = 0; i < N; ++i)
    {
        int ti = ts[i];
        if (ti > maxHi)
        {
            maxHi = ti;
            tHiRanges[i] = { ti, ti };
        }
        else
        {
            tHiRanges[i] = { 1, maxHi };
        }
    }
    maxHi = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        int ai = as[i];
        if (ai > maxHi)
        {
            maxHi = ai;
            aHiRanges[i] = { ai, ai };
        }
        else
        {
            aHiRanges[i] = { 1, maxHi };
        }
    }
    // 各山について高さの範囲の和集合を取っていく:O(N)
    LLONG ans = 1;
    for (int i = 0; i < N; ++i)
    {
        const auto tRange = tHiRanges[i];
        const auto aRange = aHiRanges[i];
        // 和集合が空になるときはゼロを出力
        if (tRange.second < aRange.first || aRange.second < tRange.first)
        {
            ans = 0;
            break;
        }
        pair<int, int> range = 
            { max(tRange.first, aRange.first),
              min(tRange.second, aRange.second) };
        ans *= (range.second - range.first + 1);
        ans %= MOD;
    }
    cout << ans << endl;
}
