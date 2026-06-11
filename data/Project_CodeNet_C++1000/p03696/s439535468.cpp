#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int stackR = 0, stackL = 0;
    int needR = 0, needL = 0;
    //必要なLの個数
    rep(i, n)
    {
        if (s[i] == ')' && stackL == 0)
            needL++;
        if (s[i] == ')' && stackL > 0)
            stackL--;
        if (s[i] == '(')
            stackL++;
    }
    //必要なRの個数
    needR = stackL;

    string res = "";
    rep(i, needL) res += '(';
    res += s;
    rep(i, needR) res += ')';

    cout << res << endl;
}

//前から見てるのでRL同様に扱うのは無理