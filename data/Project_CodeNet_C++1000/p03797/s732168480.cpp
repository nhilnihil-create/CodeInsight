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
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    if (n < m) {
    ans = (n * 2 + m) / 4;
    cout << ans << endl;
    }
    else cout << m / 2 << endl;
    return 0;
}