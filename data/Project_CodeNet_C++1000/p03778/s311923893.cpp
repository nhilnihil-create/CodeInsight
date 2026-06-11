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
    int w, a, b;
    cin >> w >> a >> b;
    int ans = 0;
    if (a + w < b)
    {
        cout << b - (a + w) << endl;
    }
    else if (b + w < a)
    {
        cout << a - (b + w) << endl;
    }
    else cout << 0 << endl;
    return 0;
}