#pragma GCC optimize("O3") //コンパイラ最適化用

#define _GLIBCXX_DEBUG //配列に[]でアクセス時のエラー表示
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
// Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはメントされる
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--) //ループ変数は1ずつデクリ
#define FOR(i, a, b) for (ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i > ll(b); i--) //ループ変数は1ずつデクリ
// xにはvectorなどのコンテナ
#define ALL(x) x.begin(), x.end() // sortなどの引数を省略したい
#define SIZE(x) ll(x.size())      // sizeをsize_tからllに直しておく
//定数
#define INF 1000000000000 // 10^12:極めて大きい値,∞
#define MOD 1000000007    // 10^9+7:合同式の法
#define MAXR 100000 // 10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB push_back // vectorヘの挿入
#define MP make_pair // pairのコンストラクタ
#define F first      // pairの一つ目の要素
#define S second     // pairの二つ目の要素
#define Umap unordered_map
#define Uset unordered_set
const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000

int main() {
    string S;
    cin >> S;
    ll cur = S.length();
    bool fl = true;

    while (true) {
        if (cur == 0) {
            break;
        } else if (cur >= 7) {
            if (S.substr(cur - 7, 7) == "dreamer") {
                cur -= 7;
            } else if (S.substr(cur - 6, 6) == "eraser") {
                cur -= 6;
            } else if (S.substr(cur - 5, 5) == "erase" ||
                       S.substr(cur - 5, 5) == "dream") {
                cur -= 5;
            } else {
                fl = false;
                break;
            }

        } else if (cur >= 6) {
            if (S.substr(cur - 6, 6) == "eraser") {
                cur -= 6;
            } else if (S.substr(cur - 5, 5) == "erase" ||
                       S.substr(cur - 5, 5) == "dream") {
                cur -= 5;
            } else {
                fl = false;
                break;
            }
        } else if (cur >= 5) {
            if (S.substr(cur - 5, 5) == "erase" ||
                S.substr(cur - 5, 5) == "dream") {
                cur -= 5;
            } else {
                fl = false;
                break;
            }
        }

        else {
            fl = false;
            break;
        }
    }
    fl ? cout << "YES" << endl : cout << "NO" << endl;
}
