#include <iostream>
#include <iomanip>
#include <string>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int need_left = 0, pointer = 0;//pointer は　小さい方の計算　needleftは大きく囲うための変数
    repi(i, n, 0)
    {
        if (s[i] == '(')
            ++pointer;
        else
        {
            if (pointer == 0)
                ++need_left;
            else
                --pointer;
        }
    }
    int need_right = pointer;

    string res = "";
    repi(i, need_left, 0) res += '(';
    res += s;
    repi(i, need_right, 0) res += ')';
    cout << res << endl;
    return 0;
}