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
    LLONG N, C, K; cin >> N >> C >> K;
    vector<LLONG> ts(N);
    for (auto &ti : ts) cin >> ti;
    sort(ts.begin(), ts.end());
    LLONG num = 0;
    LLONG start = 0;
    LLONG ans = 0;
    for (int i = 0; i < N; ++i)
    {
        // 新しいバスを追加
        if (num == 0)
        {
            start = ts[i];
            ++ans;
        }
        // 待ちきれない乗客が来た場合，新しいバスを手配
        else if (ts[i] > start + K)
        {
            start = ts[i];
            ++ans;
            num = 0;
        }
        ++num;
        // 乗員が一杯になったら次のバスにする
        if (num == C)
        {
            num = 0;
        }
    }
    cout << ans << endl;
}
