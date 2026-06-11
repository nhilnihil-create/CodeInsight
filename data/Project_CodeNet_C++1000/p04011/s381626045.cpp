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
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    int ans = 0;
    if(n > k) ans = x * k + y * (n - k);
    else ans = x * n;
    cout << ans << endl;
    return 0;
}