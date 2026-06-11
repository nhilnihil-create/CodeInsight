#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
#define PI 3.14159265359 //πの値
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define C(x) cout << x << endl //テスト出力

//関数
//nCkの計算の関数(呼び出しは[cbn])
ll cbn(ll n, ll k) {
    ll r = 1;
    for (ll d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}
// a^n mod を計算する
ll powmod(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
//２つの最大公約数
int gcb(int a, int b){
    if(a < b){
        int x = a;
        a = b;
        b = x;
    }
    int amari = a % b;
    if(amari == 0) return b;

    return gcb(b, amari);
}
//３つの最大公約数
int gcb_3(int a, int b, int c){
    return gcb(gcb(a, b), c);
}
/*-----------------------------ここから-----------------------------*/

int main() {
cin.tie(0);
ios::sync_with_stdio(false);
ll n; cin>>n;
if(n==1) cout << n;
else if(n<4) cout << 2;
else if(n<8) cout << 4;
else if(n<16) cout << 8;
else if(n<32) cout << 16;
else if(n<64) cout << 32;
else cout << 64;
}