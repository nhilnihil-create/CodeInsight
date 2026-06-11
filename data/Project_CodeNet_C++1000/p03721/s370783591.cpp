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
    int N;
    ll K;
    cin >> N >> K;
    vector<pair<ll, ll>> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i].first >> v[i].second;

    // ソート
    sort(v.begin(), v.end());

    // a_i が小さい順に b_i を合計して K 以上になる瞬間をとらえる
    ll res = 0;
    ll sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += v[i].second;
        if (sum >= K)
        {
            res = v[i].first; // sum >= K になった瞬間の a_i
            break;
        }
    }
    cout << res << endl;
}