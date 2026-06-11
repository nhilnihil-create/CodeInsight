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
#include <unordered_set>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N; cin >> N;
    LLONG t = 1, a = 1;
    // ti : ai を満たすなるべく小さな値に更新していく : O(N)
    for (int i = 0; i < N; ++i)
    {
        LLONG ti, ai; cin >> ti >> ai;    // ti:ai 互いに素
        // これまでの t, a を超えるような比を計算し，大きい側の比に合わせる
        LLONG tr = t % ti == 0 ? t / ti : t / ti + 1;
        LLONG ar = a % ai == 0 ? a / ai : a / ai + 1;
        LLONG r = max(tr, ar);
        t = r * ti;
        a = r * ai;
    }
    cout << t + a << endl;
}
