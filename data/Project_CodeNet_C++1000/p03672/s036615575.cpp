#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
const int inf = 1e9; //1(1倍)e(指数)9(10^9)
//const ll MX = 1e18; //1(1倍)e(指数)18(10^18)
//const ll MOD = 1e9 + 7; //1000000007で割った余りを聞かれたら使う
//加算代入演算子は+=
//int 2^31 10^9まで
//intは10桁、long longは18桁、doubleは308桁、long double は4932桁
//10^10くらいまででdoubleは誤差が発生しちゃう。なるべく整数にすること
//doubleからlong longにキャストするときは、+0.5で切り捨ての誤差を調整
//__int128()で128bit対応の整数（多倍長整数）
//||は片方が成り立つとき
int main()
{
    string str;
    cin >> str;
    int n = str.size();
    string tmp = str.substr(0, n - 1);
    while (tmp.size() >= 2)
    {
        if (tmp.size() % 2 == 0)
        {
            string prev = tmp.substr(0, tmp.size() / 2);
            string post = tmp.substr(tmp.size() / 2, tmp.size() / 2);
            if (prev == post)
            {
                int ans = tmp.size();
                printf("%d\n", ans);
                return 0;
            }
        }
        tmp = tmp.substr(0, tmp.size() - 1);
    }
    return 0;
}