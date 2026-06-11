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
    // 3+2+2+10+10+10+10+10+10
    int n, t;
    cin >> n >> t;
    vector<int> vec(n);
    rep(i, n) cin >> vec[i];
    ll ans = 0;
    rep(i, n - 1) {
        if(vec[i + 1] - vec[i] < t) {
            ans += vec[i + 1] - vec[i];
        }
        else {
            ans += t;
        }
    }
    cout << ans + t << endl;
    return 0;
}