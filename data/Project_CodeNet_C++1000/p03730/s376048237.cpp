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
//intは10桁、long longは18桁、doubleは308桁、long double は4932桁
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    bool ans = false;
    rep(i, b)
    {
        if (a * i % b == c)
        {
            ans = true;
            break;
        }
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}