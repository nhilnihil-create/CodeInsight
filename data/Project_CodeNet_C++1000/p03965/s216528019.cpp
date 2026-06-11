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
    string s; cin >> s;
    // 常にあいこにすることはできるので，得点０は保証される
    // わざと負けることに意味はない
    // -> パーを出せるならパーを出す。出せないならグー
    int score = 0;
    int pNum = 0, gNum = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        char ch = s[i];
        // グーしか出せないとき
        if (pNum + 1 > gNum)
        {
            score = ch == 'g' ? score : score - 1;
            ++gNum;
        }
        else {
            score = ch == 'g' ? score + 1 : score;
            ++pNum;
        }
    }
    cout << score << endl;
}
