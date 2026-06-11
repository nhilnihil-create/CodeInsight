#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
//const int inf = 1e9; //1(1倍)e(指数)9(10^9)
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
    ll H, W;
    cin >> H >> W;

    ll ans = H * W;
    ll s[3];
    for (int i = 0; i < 2; ++i) //2回繰り返す
    {
        for (ll h = 1; h < H; ++h)
        {
            // まずは縦割り
            s[0] = h * W; //最初の分割部分
            s[1] = (H - h) * (W / 2); //余ったところを分割
            s[2] = H * W - (s[0] + s[1]); //余ったところ
            sort(s, s + 3); //配列昇順ソート
            ans = min(ans, s[2] - s[0]); //max-minの結果を保持して比較してく
            // 次いで横割り
            s[0] = h * W;
            s[1] = ((H - h) / 2) * W;
            s[2] = H * W - (s[0] + s[1]);
            sort(s, s + 3);
            ans = min(ans, s[2] - s[0]);
        }
        // 板チョコを90度回す
        swap(H, W);
    }
    cout << ans << endl;
    return 0;
}