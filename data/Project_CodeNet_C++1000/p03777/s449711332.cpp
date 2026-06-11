#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
const int inf = 1000000000; //10^9
const ll MOD = 1e9 + 7;
//加算代入演算子は+=！！！！！
//int 2^31 10^9まで
int main()
{
    char a, b;
    cin >> a >> b;
    bool B = false;
    if (a == 'H')
    {

        if (b == 'H')
        {
            cout << 'H' << endl;
        }
        if (b == 'D')
        {
            cout << 'D' << endl;
        }
    }
    else if (a = 'D')
    {
        if (b == 'H')
        {
            cout << 'D' << endl;
        }
        if (b == 'D')
        {
            cout << 'H' << endl;
        }
    }
    return 0;
}