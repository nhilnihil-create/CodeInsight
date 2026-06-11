#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
using namespace std;
#define rep(i,a,b) for(int64_t i=(a); i<(b); ++i) // a ≦ i < b 
#define Rrep(i,a,b) for(int64_t i=(a);i>=(b);--i) // reverse repeat. a から b まで減少．
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend() //逆イテレータ
#define INF 10000000000000
#define MOD 1000000007LL
#define RANGE(a,b,c) (a).begin()+(b),(a).begin()+(c) // [b,c) イテレータ
using PII = pair<int64_t, int64_t>;
using VI = vector<int64_t>;
using VVI = vector<VI>;
using VS = vector<string>;
using VP = vector<PII>;
using i64 = int64_t;
// input vector
template<typename T>
void invec(vector<T> &A){for(T& a : A) cin >> a;}


int main() {
cin.tie(0);
ios::sync_with_stdio(false);

int H, W; cin >> H >> W;
VS a(H); invec(a);
VI cnt(26, 0);
for(string s: a) for(char c: s) ++cnt[c - 'a'];
//4つ組の数
int c4 = W/2 * (H/2);
//2つ組の数
int c2 = W%2 * (H/2) + H%2 * (W/2);
// 中心1つ
int c1 = W%2 * H%2;

rep(i, 0, 26){
    if (c4){
        c4 -= cnt[i] / 4;
        cnt[i] %= 4;
    }
    if (c2){
        c2 -= cnt[i] / 2;
        cnt[i] %= 2;
    }
    if (c1) {
        c1 -= cnt[i];
        cnt[i]= 0;
    }
}
if (all_of(ALL(cnt), [](int i){return i == 0;}))
    cout << "Yes\n";
else 
    cout << "No\n";


}
// 書いて考える．場合分け
// 境界，出力文字列 チェック．行末にスペース入れない．
// 可読性優先．高速化次点．
// まずは全探索，分割統治，次にDP
// 制限を見る．境界に注意．求めたい量の変域．動かせる量．
// 偶奇，逆から，ソート，出現回数，出現位置，DP， 余事象，包除
// データ構造． 問題の特徴量．単調性，二分探索
// 存在判定：構成方法，入力の特徴
// gcd, lcm ,素因数分解．
// 例外を十分に含む一般化．想像力の限界
// 小さい系から例示
// 代数的処理．前処理によるクエリ高速化．
// 始めは過剰に例示・場合分けしてもいい．各場合を確実に対処．
// 自明な例から処理，除外．
// 小数のときは，精度の設定する．doubel 変数に数値を入力するときは 123. とする．
// テストケース作成は数表あり
// 実行エラー：vector添え字超え．0割り．

