#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define all(v) v.begin(), v.end()
const int inf = 1000000000; //10^9
using ll = long long;
using P = pair<int, int>;
//加算代入演算子は+=！！！！！
//int 2^31 10^9まで
int main()
{
    ll n, count = 0, ans = 1;
    cin >> n;
    vector<ll> vec(n);
    rep(i, n) cin >> vec.at(i);
    sort(vec.begin(), vec.end());
    bool can = true;
    rep(i, n - 1)
    {
        if (n % 2 != 0 && vec[i] == 0 && vec[i] == vec[i + 1])
        {
            can = false;
            break;
        }
        else if (i < n - 2 && vec[i] == vec[i + 1] && vec[i + 1] == vec.at(i + 2))
        {
            can = false;
            break;
        }
    }
    if (can)
    {
        rep(i, n - 1)
        {
            if (vec[i] == vec[i + 1])
            {
                count++;
            }
        }
        for (int i = 0; i < count; i++)
        {
            ans *= 2;
            ans %= 1000000007;
        }
        cout << ans << endl;
    }
    else cout << 0 << endl;
    return 0;
}
