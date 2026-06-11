#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define all(v) v.begin(), v.end()
const int inf = 1000000000; //10^9
using ll = long long;
using P = pair<int, int>;
//加算代入演算子は+=！！！！！

int main()
{
    int n;
    cin >> n;
    vector<ll> t(n), a(n);
    rep(i, n) cin >> t[i] >> a[i];
    ll total_t = 1, total_a = 1; //合計投票数をとりあえず最小の1にする。
    rep(i, n)
    {
        ll x = total_t / t[i]; //n番目のTへの合計投票数（合計投票数 * 比率）
        ll y = total_a / a[i]; //n番目のAへの合計投票数
        if (total_t % t[i] != 0) x++; //切り捨てられちゃうから余りがあるときはxを加算する。
        if (total_a % a[i] != 0) y++;
        ll temp = max(x, y);
        total_t = temp * t[i];
        total_a = temp * a[i];
    }
    cout << total_t + total_a << endl;
    return 0;
}