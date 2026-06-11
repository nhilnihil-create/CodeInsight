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
    int K, T; cin >> K >> T;
    vector<int> as(T); for (auto &ai : as) cin >> ai;
    int tmpIndex = -1, tmpNum = -1;
    int ans = 0;
    for (int i = 0; i < K; ++i)
    {
        // 現時点で最も残っているケーキから順に食べる
        auto itr = max_element(as.begin(), as.end());
        *itr -= 1;
        // なるべく連続して食べないように，今日食べたケーキの残数を０に置き換えておく
        if (tmpIndex >= 0)
        {
            as[tmpIndex] = tmpNum;
        }
        tmpIndex = distance(as.begin(), itr);
        tmpNum = *itr;
        as[tmpIndex] = 0;
        // 残りのケーキの種類が１通りになってしまったら，後は連続で食べるしかない
        if (count(as.begin(), as.end(), 0) == T)
        {
            ans = K - 1 - i;
            break;
        }
    }
    cout << ans << endl;
}
