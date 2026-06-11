#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 998244353;

int main()
{
    string A;
    cin >> A;
    // Ai != Aj (i<j) であるような (i,j) のペア数を数える
    // →全ペア数から Ai == Aj であるペア数を引く
    LLONG N = A.size();         // LLONG型で宣言しないと次のN^2の計算でエラー
    LLONG ans = N * (N - 1) / 2;
    map<char, LLONG> char2NumMap;
    // 各文字の数を数える：O(N)
    for (const char &ch : A)
    {
        ++char2NumMap[ch];
    }
    // 文字ごとに Ai == Aj となりうるペア数を引く：O(1)
    for (const auto &kvp : char2NumMap)
    {
        const LLONG num = kvp.second;
        ans -= num * (num - 1) / 2;
    }
    // 「操作を行わない」１通りを加えたものが答え
    cout << ans + 1 << endl;
}
